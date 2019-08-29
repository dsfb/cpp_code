#include <iostream>
using namespace std;

struct node
{
    node()
    {
        left = nullptr;
        right = nullptr;
    }
    int value;
    node* left;
    node* right;
};

class tree : public node
{
public:
    tree()
    {
        isAddedRoot = false;
        depth = 0;
    }

    template <typename type>
    void add_pack(type arg)
    {
        add(arg);
    }

    template <typename type, typename ... types>
    void add_pack(type arg, types... args)
    {
        add(arg);
        add_pack(args...);
    }

    void add(int value)
    {
        // if is a first node
        if (!isAddedRoot/*left == nullptr && right == nullptr*/)
        {
            cout << "add root value " << value << endl;
            this->value = value;
            isAddedRoot = true;
            return;
        }

        depth = 0;
        find_end(value, this);
    }

    void find_end(const int value, node* active)
    {
        depth++;
        bool isLeftSide = value <= active->value;
        bool isRightSide = !isLeftSide;

        if (isLeftSide)
        {
            //cout << "is left side" << endl;
            if (active->left == nullptr)
            {
                cout << "add to left side " << value << endl;
                active->left = new node();
                active = active->left;
                active->value = value;
            }
            else
            {
                active = active->left;
                find_end(value, active);
            }
        }

        // is right side
        else
        {
            //cout << "is right side" << endl;
            if (active->right == nullptr)
            {
                cout << "add to right side " << value << endl;
                active->right = new node();
                active = active->right;
                active->value = value;
            }
            else
            {
                active = active->right;
                find_end(value, active);
            }
        }
    }

    int max_distinct_count(/*node* leaf*/)
    {
        max.clear();
        set<int>* numbers = new set<int>;
        distinct_count_back(numbers, this);
        
        for (auto&& element : max)
            cout << "some max = " << element << endl;
        
        if (max.empty())
            return 0;

        auto it = std::max_element(max.begin(), max.end());

        return *it;
    }


    void distinct_count_back(set<int>* numbers, node* leaf)
    {

        numbers->insert(leaf->value);
        
        bool leftWay = leaf->left != nullptr;
        bool rightWay = leaf->right != nullptr;
        bool oneWay = leftWay != rightWay;
        bool noWay = leftWay == false && rightWay == false;
        bool twoWays = leftWay == true && rightWay == true;

        /*
        cout << boolalpha;
        cout << "value = " << leaf->value << endl;
        cout << "is left way = " << leftWay << endl;
        cout << "is right way = " << rightWay << endl;
        cout << "is one way = " << oneWay << endl;
        cout << "is no way = " << noWay << endl;
        cout << "is two ways = " << twoWays << endl;
        cout << endl;
        */


        // jeśli to koniec jakiejś ścieżki
        if (noWay)
        {
            //cout << "is the end" << endl;
            max.push_back(numbers->size());
            delete numbers;
            return;
        }


        // jeśli idę w lewo
        if (oneWay && leftWay) {
            //cout << "go left" << endl;
            distinct_count_back(numbers, leaf->left);
        }
        
        // jeśli idę w prawo
        else if (oneWay && rightWay){
            //cout << "go right" << endl;
            distinct_count_back(numbers, leaf->right);
        }
        
         
        else if (twoWays) {
            //cout << "there are two ways" << endl;
            // robię kopię ścieżki dla nowej gałęzi
            set<int>* numbers_copy = new set<int>;
            for (auto it = numbers->begin(); it != numbers->end(); it++)
            {
                numbers_copy->insert(*it);
            }

            distinct_count_back(numbers, leaf->left);
            distinct_count_back(numbers_copy, leaf->right);
        }
    }

    void print()
    {
        cout << "start printing" << endl;
        print_node(depth, this);
    }

    void print_node(int depth, node* leaf)
    {
        //print_space(depth);
        //depth--;
        bool leftWay = leaf->left;
        bool rightWay = leaf->right;
        bool isEnd = leftWay == false && rightWay == false;
        bool newBranch = leftWay == true && rightWay == true;

        if (newBranch)
            cout << '<' << leaf->value << "> ";
        else cout << leaf->value << ' ';

        if(isEnd || newBranch)
            cout << endl;

        if (leaf->left)
        {
            leftWay = true;
            print_node(depth, leaf->left);
        }
        
        if (leaf->right){
            rightWay = true;
            print_node(depth, leaf->right);   
        }

        
    }

private:

    void print_space(int depth)
    {
        while(depth > 0)
        {
            cout << ' ';
            --depth;
        }

    }

    bool isAddedRoot;
    short depth;
    vector<int> max;
};

int main()
{
    cout << "the program is valid" << endl;

    tree t;
    t.add_pack(20, 10, 10, 6, 4, 2); // 5
    t.add_pack(30, 40, 50, 60, 70);
    t.add_pack(51, 52, 53, 54, 55, 56, 57, 58);

    cout << endl;
    t.print();

    cout << endl;
    auto distinct = t.max_distinct_count();
    
    cout << endl;
    cout << "max distinct count = " << distinct << endl;
}

/*
clear; .\g++ -g -std=c++14 'C:\Users\Alex\Desktop\code\main.cpp' -o 'main.exe'; .\main.exe
*/
