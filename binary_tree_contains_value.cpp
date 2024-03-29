/* 
hello. look at my code. I had to create a binary tree as a test for 
a job interview. I had to write a method to check if a value contains
 or not. I use newest C++ features here. Lastly I added the function
for remove. I used a virtual desctructor and virtual.
what's more I added the visitor pattern support as good as it possible.
the visitor it's real carte blanche. it permits do anything. 

Aleksander Czastuchin
first version - 2017
second verison - 2019

g++ -std=c++17 binary_tree_contains_value.cpp -o main.exe  && ./main.exe
 */
#include <string>
#include <iostream>
#include <functional>

using namespace std;

struct node
{
	node()
	{
		left = nullptr;
		right = nullptr;
		value = 0;
	}

	int value;
	node* left;
	node* right;

	virtual ~node()
	{
		cout << "the destructor runs for " << value << '\n';
		remove_all(this);
	}

protected:

	virtual void remove_all(node* leaf) 
	{
		delete leaf->left;
		delete leaf->right;
		leaf->left = nullptr;
		leaf->right = nullptr;
	};
};

struct binary_tree : node
{
	template <typename type>
	static void visitor(const node* const& leaf, const function<void (const type&)>& callable)
	{
		callable(leaf->value); // do what you want
		if (leaf->left)
			visitor(leaf->left, callable);	
		if (leaf->right)
			visitor(leaf->right, callable);
	}

	static bool contains(const node* leaf, const int& value)
	{
		if (leaf->value == value)
			return true;
		
		if (leaf->left)
			if (contains(leaf->left, value))
				return true;
		
		if (leaf->right)
			if (contains(leaf->right, value))
				return true;

		return false;
	}

	template </* typename type,*/ typename ... types>
	void add_pack(/* type arg,*/ types ... args)
	{
		//add_leaf(arg);
		//add_pack(args ...)
		(add_leaf(args), ...); // c++17 I love you
	}

	/*template <typename type>
	void add_pack(type arg)
	{
		add_leaf(arg);
	}//*/

	void add_leaf(const int& value)
	{
		add_leaf_static(this, value);
	}

	static void add_leaf_static(node* leaf, const int& value)
	{
		if (leaf->value == 0){
			leaf->value = value;
			return;
		}

		bool is_left = value <= leaf->value;
		bool is_right = value > leaf->value;

		if (is_left && leaf->left) {
			add_leaf_static(leaf->left, value);
			return;
		}
		else if (is_left) {
			leaf->left = new node();
			leaf->left->value = value;
			return;
		}

		if (is_right && leaf->right) {
			add_leaf_static(leaf->right, value);
			return;
		}
		else if (is_right) {
			leaf->right = new node();
			leaf->right->value = value;
			return;
		}
	}

	static void print(node* leaf)
	{
		cout << leaf->value;
		cout << ' ';

		if (leaf->left)
			print(leaf->left);

		if (leaf->left && leaf->right)
		cout << endl;
		
		if (leaf->right)
			print(leaf->right);	
	}

	~binary_tree()
	{
		remove_all(this);
	}

private:

	void remove_all(node* leaf) override
	{
		if (leaf->left)
			remove_all(leaf->left);
		
		if (leaf->right)
			remove_all(leaf->right);

		//  I mustn't call leaf->~node() yet and I remove like below
		binary_tree::node::remove_all(leaf); // way one
		//leaf->remove_all(leaf); // way two
	}
};

int main()
{
	binary_tree tree;
	tree.add_pack(10, 9, 8, 7, 6, 5, 4, 3, 2, 1);
	tree.add_pack(20, 30, 40, 50, 60, 70);
	tree.add_pack(21, 22, 23, 24, 25, 25);
	binary_tree::print(&tree);

	cout << boolalpha << '\n';
	cout << binary_tree::contains(&tree, 22) << '\n';
	cout << binary_tree::contains(&tree, 100) << '\n';

	cout << "\ngreater than 20\n";
	bool there_is_23 = false;
	binary_tree::visitor<int>(&tree,
	 [&there_is_23](const auto& what) { 
		 if (what == 23) {
			 there_is_23 = true;
		 }
		 if (what > 20) {
		 	cout << what << ", ";
		 }
	});

	cout << "\nthere is 23 = " << there_is_23 << '\n';


	return 0;
}