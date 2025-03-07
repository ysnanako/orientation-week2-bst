# include "BST.h"
# include <bits/stdc++.h>
using namespace std;

void BST::GetFilename(const int& argc, char *argv[])
{
    if(argc == 3)
    {
        this->input_filename = argv[1];
        this->output_filename = argv[2];
    }
    else
    {
        cerr << "Error: Parser should be executed with input file and output file. \n";
        exit(-1);
    }
}
void BST::ReadFile()
{
    fin.open(input_filename);
    if(!fin)
    {
        cerr << "Error: Input file failed. \n";
        exit(1);
    }
    string line;
    while(getline(fin, line))
    {
        if(line.substr(0, 6) == "MODULE")
            CreatNode(line);
        else if(line.substr(1, 10) == "DIMENSIONS")
            SetNode(line);
    }
    ResetContour();
    ResetXY(this->root_ptr);
    cout << "READ " << input_filename << " COMPLETE" << "\n";
}
void BST::CreatNode(string line)
{
    new_ptr = new node;
    new_ptr->name = line.substr(7, line.size() - 8);
    new_ptr->left_ptr = NULL;
    new_ptr->right_ptr = NULL;
    new_ptr->parent_ptr = NULL;
    cout << "NODE " << new_ptr->name << " CREATED\n"; // debug
    name_vec.push_back(new_ptr->name);
}
void BST::SetNode(string line)
{
    vector<int> dimensions;
    stringstream ss(line);
    string s;

    while(ss >> s)
    {
        if(s != "DIMENSIONS")
            dimensions.push_back(stoi(s));
    }
    new_ptr->width = dimensions[2];
    new_ptr->height = dimensions[3];
    if(root_ptr == NULL)
    {
        root_ptr = new_ptr;
        cout << "ROOT != NULL\n"; // debug
        SetXY(root_ptr);
        cout << "INITIAL XY: " << root_ptr->x << " " << root_ptr->y << "\n\n"; // debug
        return;
    }
    area = INT_MAX;
    FindPosition(this->root_ptr);
    new_ptr->parent_ptr = PP_ptr;
    if(this->PP_type == child_type::left)
        PP_ptr->left_ptr = new_ptr;
    if(this->PP_type == child_type::right)
        PP_ptr->right_ptr = new_ptr;
    SetXY(new_ptr);
    SetContour(new_ptr);
    cout << "NODE " << new_ptr->name << " SET\n\n"; // debug
}
void BST::FindPosition(node *ptr)
{
    if(ptr == NULL)
        return;
    if(ptr->left_ptr != NULL)
        FindPosition(ptr->left_ptr);
    else
    {
        ptr->left_ptr = new_ptr;
        new_ptr->parent_ptr = ptr;
        SetXY(new_ptr);
        boundry_v = 0;
        boundry_h = 0;
        FindBoundryV(this->root_ptr);
        FindBoundryH(this->root_ptr);
        if(boundry_v * boundry_h < this->area)
        {
            this->area = boundry_v * boundry_h;
            this->PP_type = child_type::left;
            this->PP_ptr = ptr;
        }
        ptr->left_ptr = NULL;
    }
    if(ptr->right_ptr != NULL)
        FindPosition(ptr->right_ptr);
    else
    {
        ptr->right_ptr = new_ptr;
        new_ptr->parent_ptr = ptr;
        SetXY(new_ptr);
        boundry_v = 0;
        boundry_h = 0;
        FindBoundryV(this->root_ptr);
        FindBoundryH(this->root_ptr);
        if(boundry_v * boundry_h < this->area)
        {
            this->area = boundry_v * boundry_h;
            this->PP_type = child_type::right;
            this->PP_ptr = ptr;
        }
        ptr->right_ptr = NULL;
    }
}
void BST::SetXY(node *update_ptr)
{
    node *UP_ptr = update_ptr->parent_ptr;
    if(UP_ptr == NULL)
    {
        update_ptr->x = 0;
        update_ptr->y = 0;
    }
    else if(UP_ptr->left_ptr == update_ptr)
    {
        update_ptr->x = UP_ptr->x + UP_ptr->width;
        update_ptr->y = UP_ptr->y;
        for(int i = update_ptr->x; i < update_ptr->x + update_ptr->width; ++i)
        {
            if(update_ptr->y < contour[i])
                update_ptr->y = contour[i];
        }
    }
    else if(UP_ptr->right_ptr == update_ptr)
    {
        update_ptr->x = UP_ptr->x;
        update_ptr->y = UP_ptr->y + UP_ptr->height;
        for(int i = update_ptr->x; i < update_ptr->x + update_ptr->width; ++i)
        {
            if(update_ptr->y < contour[i])
                update_ptr->y = contour[i];
        }
    }
    return;
}
void BST::FindBoundryV(node *ptr)
{
    if(ptr == NULL)
        return;
    if(ptr->left_ptr != NULL)
        FindBoundryV(ptr->left_ptr);
    if(ptr->x + ptr->width > boundry_v)
        boundry_v = ptr->x + ptr->width;
    if(ptr->right_ptr != NULL)
        FindBoundryV(ptr->right_ptr);
}
void BST::FindBoundryH(node *ptr)
{
    if(ptr == NULL)
        return;
    if(ptr->left_ptr != NULL)
        FindBoundryH(ptr->left_ptr);
    if(ptr->y + ptr->height > boundry_h)
        boundry_h = ptr->y + ptr->height;
    if(ptr->right_ptr != NULL)
        FindBoundryH(ptr->right_ptr);
}
void BST::SetContour(node *update_ptr)
{
    for(int i = update_ptr->x; i < update_ptr->x + update_ptr->width; ++i)
        contour[i] = update_ptr->y + update_ptr->height;
}
void BST::WriteFile()
{
    fout.open(output_filename);
    if(!fout)
    {
        cerr << "Error : Output file failed. \n";
        exit(1);
    }
    fout << "axis equal;\n" << "hold on\n" << "grid on\n";
    WriteNode(this->root_ptr);
}
void BST::WriteNode(node *ptr)
{
    if(ptr == NULL)
        return;
    fout << "block_x=[";
    fout << " " << ptr->x;
    fout << " " << ptr->x;
    fout << " " << ptr->x + ptr->width;
    fout << " " << ptr->x + ptr->width;
    fout << " " << ptr->x;
    fout << "];\n";
    fout << "block_y=[";
    fout << " " << ptr->y;
    fout << " " << ptr->y + ptr->height;
    fout << " " << ptr->y + ptr->height;
    fout << " " << ptr->y;
    fout << " " << ptr->y;
    fout << "];\n";
    fout << "fill(block_x,block_y,'c');\n";
    fout << "text(" << ptr->x + ptr->width / 2 << "," << ptr->y + ptr->height / 2 << ",";
    fout << "'" << ptr->name << "');\n";
    if(ptr->left_ptr != NULL)
        WriteNode(ptr->left_ptr);
    if(ptr->right_ptr != NULL)
        WriteNode(ptr->right_ptr);
}
void BST::RotateModule()
{
    module_ptr = NULL;
    FindModule(this->root_ptr);
    if(module_ptr == NULL)
    {
        cout << "INVALID MODULE\n";
        return;
    }
    int temp;
    temp = module_ptr->width;
    module_ptr->width = module_ptr->height;
    module_ptr->height = temp;
    ResetContour();
    ResetXY(this->root_ptr);
}
void BST::DeleteModule()
{
    module_ptr = NULL;
    FindModule(this->root_ptr);
    if(module_ptr == NULL)
    {
        cout << "INVALID MODULE\n";
        return;
    }
    MP_ptr = module_ptr->parent_ptr;
    if(MP_ptr == NULL)
    {
        MP_type = child_type::null;
        this->root_ptr = module_ptr->left_ptr;
        this->root_ptr->parent_ptr = NULL;
        module_ptr->left_ptr = NULL;
    }
    else if(MP_ptr->left_ptr == module_ptr)
    {
        MP_type = child_type::left;
        MP_ptr->left_ptr = module_ptr->left_ptr;
        if(MP_ptr->left_ptr != NULL)
            MP_ptr->left_ptr->parent_ptr = MP_ptr;
        module_ptr->left_ptr = NULL;
    }
    else if(MP_ptr->right_ptr == module_ptr)
    {
        MP_type = child_type::right;
        MP_ptr->right_ptr = module_ptr->right_ptr;
        if(MP_ptr->right_ptr != NULL)
            MP_ptr->right_ptr->parent_ptr = MP_ptr;
        module_ptr->right_ptr = NULL;
    }
    new_ptr = module_ptr;
    area = INT_MAX;
    FindPosition(this->root_ptr);
    module_ptr->parent_ptr = PP_ptr;
    if(this->PP_type == child_type::left)
        PP_ptr->left_ptr = new_ptr;
    if(this->PP_type == child_type::right)
        PP_ptr->right_ptr = new_ptr;
    ResetContour();
    ResetXY(this->root_ptr);
}
void BST::SwapModule(string a_name, string b_name)
{
    node *a_ptr, *b_ptr;
    module_name = a_name;
    module_ptr = NULL;
    FindModule(this->root_ptr);
    if(module_ptr == NULL)
    {
        cout << "INVALID MODULE\n";
        return;
    }
    a_ptr = module_ptr;
    module_name = b_name;
    module_ptr = NULL;
    FindModule(this->root_ptr);
    if(module_ptr == NULL)
    {
        cout << "INVALID MODULE\n";
        return;
    }
    b_ptr = module_ptr;
    int a_x = a_ptr->x;
    int a_y = a_ptr->y;
    int a_width = a_ptr->width;
    int a_height = a_ptr->height;
    a_ptr->name = b_name;
    a_ptr->x = b_ptr->x;
    a_ptr->y = b_ptr->y;
    a_ptr->width = b_ptr->width;
    a_ptr->height = b_ptr->height;
    b_ptr->name = a_name;
    b_ptr->x = a_x;
    b_ptr->y = a_y;
    b_ptr->width = a_width;
    b_ptr->height = a_height;
    ResetContour();
    ResetXY(this->root_ptr);
}
void BST::FindModule(node *ptr)
{
    if(ptr == NULL)
        return;
    if(ptr->left_ptr != NULL)
        FindModule(ptr->left_ptr);
    if(ptr->name == module_name)
        module_ptr = ptr;
    if(ptr->right_ptr != NULL)
        FindModule(ptr->right_ptr);
}
void BST::ResetXY(node *ptr)
{
    if(ptr == NULL)
        return;
    SetXY(ptr);
    SetContour(ptr);
    if(ptr->left_ptr != NULL)
        ResetXY(ptr->left_ptr);
    if(ptr->right_ptr != NULL)
        ResetXY(ptr->right_ptr);
}
void BST::ResetContour()
{
    for(size_t i = 0; i < contour.size(); ++i)
        contour[i] = 0;
}
void BST::SA()
{    
    srand(time(0));
    double temp = init_temp;
    double rate = cool_rate;
    double cur_score = init_score;
    double new_score;
    state_type perturbation;
    string a_name, b_name;
    while(temp > 1)
    {
        perturbation = static_cast<state_type>(rand() % 5);
        switch (perturbation)
        {
            case state_type::rot:
                module_name = name_vec[rand() % name_vec.size()];
                RotateModule();
                break;
            case state_type::del:
                module_name = name_vec[rand() % name_vec.size()];
                DeleteModule();
                break;
            case state_type::swap:
                module_name = name_vec[rand() % name_vec.size()];
                a_name = module_name;
                module_name = name_vec[rand() % name_vec.size()];
                b_name = module_name;
                SwapModule(a_name, b_name);
                break;
            default:
                module_name = name_vec[rand() % name_vec.size()];
                RotateModule();
                break;
        }
        boundry_v = 0;
        boundry_h = 0;
        FindBoundryV(root_ptr);
        FindBoundryH(root_ptr);
        new_score = boundry_v > boundry_h ? (boundry_v * boundry_v) : (boundry_h * boundry_h); // score = ratio * area
        if(Acceptance(cur_score, new_score, temp) < (double)rand() / RAND_MAX)
        {
            switch (perturbation)
            {
                case state_type::rot:
                    RotateModule();
                    break;
                case state_type::del:
                    InsertModule();
                    break;
                case state_type::swap:
                    SwapModule(a_name, b_name);
                    break;
                default:
                    RotateModule();
                    break;
            }
        }
        else
            cur_score = new_score;
        temp *= 1 - rate;
        cout << "temp: " << temp << "\n";
    }
}
double BST::Acceptance(double cur_score, double new_score, double temp)
{
    if(new_score < cur_score)
        return 1.0;
    return exp((cur_score - new_score) / temp);
}
void BST::InsertModule()
{
    if(MP_type == child_type::null)
    {  
        module_ptr->left_ptr = this->root_ptr;
        module_ptr->parent_ptr = NULL;
        this->root_ptr->parent_ptr = module_ptr;
        this->root_ptr = module_ptr;
    }
    else if(MP_type == child_type::left)
    {
        module_ptr->left_ptr = MP_ptr->left_ptr;
        module_ptr->parent_ptr = MP_ptr;
        if(MP_ptr->left_ptr != NULL)
            MP_ptr->left_ptr->parent_ptr = module_ptr;
        MP_ptr->left_ptr = module_ptr;
    }
    else if(MP_type == child_type::right)
    {
        module_ptr->right_ptr = MP_ptr->right_ptr;
        module_ptr->parent_ptr = MP_ptr;
        if(MP_ptr->right_ptr != NULL)
            MP_ptr->right_ptr->parent_ptr = module_ptr;
        MP_ptr->right_ptr = module_ptr;
    }
    if(this->PP_type == child_type::left)
        PP_ptr->left_ptr = NULL;
    if(this->PP_type == child_type::right)
        PP_ptr->right_ptr = NULL;
    ResetContour();
    ResetXY(this->root_ptr);
}