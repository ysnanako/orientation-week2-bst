# ifndef BST_H
# define BST_H

# include <bits/stdc++.h>
using namespace std;

#define init_temp 1000000
#define cool_rate 0.00001
#define init_score numeric_limits<double>::max()

struct node
{
    string name;
    int x, y, width, height;
    node *left_ptr, *right_ptr, *parent_ptr;
};
enum class child_type{null, left, right};
enum class state_type{null, rot, del, swap, sa, done};

class BST
{
    public:
    string input_filename, output_filename;
    node *root_ptr = NULL;
    vector<int> contour;
    void GetFilename(const int& argc, char *argv[]);
    void ReadFile();
    string module_name; // perturbution
    void RotateModule();
    void DeleteModule();
    void SwapModule(string, string);
    void WriteFile();
    void SA();
    private:
    ifstream fin;
    ofstream fout;
    node *new_ptr, *PP_ptr; // Position Parent
    child_type PP_type;
    int boundry_v, boundry_h, area;
    void CreatNode(string);
    void SetNode(string);
    void FindPosition(node *);
    void SetXY(node *);
    void FindBoundryV(node *);
    void FindBoundryH(node *);
    void SetContour(node *);
    void WriteNode(node *);
    node *module_ptr, *MP_ptr; // Module Parent
    child_type MP_type;
    void FindModule(node *);
    void ResetXY(node *);
    void ResetContour();
    vector<string> name_vec; // SA
    double Acceptance(double, double, double);
    void InsertModule();
};

# endif