# include "BST.h"
# include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    BST BST_obj;
    BST_obj.contour.resize(1000000);
    BST_obj.GetFilename(argc, argv);
    BST_obj.ReadFile();

    state_type FSM = state_type::null;
    while(FSM != state_type::done)
    {
        string temp;
        if(FSM == state_type::null)
        {
            cout << "\nPERTURBATION(rotate, delete, swap) SA(sa) DONE(done) ";
            cin >> temp;
            if(temp == "done")
                FSM = state_type::done;
            else if(temp == "rotate")
                FSM = state_type::rot;
            else if(temp == "delete")
                FSM = state_type::del;
            else if(temp == "swap")
                FSM = state_type::swap;
            else if(temp == "sa")
                FSM = state_type::sa;
            else
                cout << "INVALID COMMAND\n";
            continue;
        }
        else if(FSM == state_type::rot)
        {
            cout << "ROTATE MODULE: ";
            cin >> BST_obj.module_name;
            BST_obj.RotateModule();
            cout << "ROTATE " << BST_obj.module_name << " COMPLETE\n";
        }
        else if(FSM == state_type::del)
        {
            cout << "DELETE MODULE: ";
            cin >> BST_obj.module_name;
            BST_obj.DeleteModule();
            cout << "DELETE " << BST_obj.module_name << " COMPLETE\n";
        }
        else if(FSM == state_type::swap)
        {
            string a_name, b_name;
            cout << "INSERT MODULE_A: ";
            cin >> a_name;
            cout << "INSERT MODULE_B: ";
            cin >> b_name;
            BST_obj.SwapModule(a_name, b_name);
            cout << "SWAP " << a_name << " " << b_name << " COMPLETE\n";

        }
        else if(FSM == state_type::sa)
            BST_obj.SA();
        FSM = state_type::null;
    }
    BST_obj.WriteFile();
    cout << "WRITE " << BST_obj.output_filename << " COMPLETE\n";
    return 0;
}