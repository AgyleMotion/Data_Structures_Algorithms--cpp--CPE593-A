
#include <iostream>
#include <queue>
using namespace std;

struct Employee {
    int employeeID;
    string name;
    double salary;
    string department;
    Employee* left;
    Employee* right;
};

// Function to create a new Employee node
Employee* newEmployee(int id, string name, double salary, string department) {
    Employee* new_employee = new Employee;
    new_employee->employeeID = id;
    new_employee->name = name;
    new_employee->salary = salary;
    new_employee->department = department;
    new_employee->left = NULL;
    new_employee->right = NULL;
    return new_employee;
}

// Function to insert a new employee record
Employee* insert(Employee* root, int employeeID, string name, double salary, string department) {
    if (root == NULL) {
        return newEmployee(employeeID, name, salary, department);
    }

    if (employeeID < root->employeeID) {
        root->left = insert(root->left, employeeID, name, salary, department);
    } else if (employeeID > root->employeeID) {
        root->right = insert(root->right, employeeID, name, salary, department);
    }

    return root;
}

// Function for pre-order traversal
void preOrder(Employee* root) {
    if (root == NULL) {
        return;
    }
    cout << "Employee ID: " << root->employeeID
         << ", Name: " << root->name
         << ", Salary: " << root->salary
         << ", Department: " << root->department << endl;
    preOrder(root->left);
    preOrder(root->right);
}

// Function for in-order traversal
void inOrder(Employee* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << "Employee ID: " << root->employeeID
         << ", Name: " << root->name
         << ", Salary: " << root->salary
         << ", Department: " << root->department << endl;
    inOrder(root->right);
}

// Function for post-order traversal
void postOrder(Employee* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << "Employee ID: " << root->employeeID
         << ", Name: " << root->name
         << ", Salary: " << root->salary
         << ", Department: " << root->department << endl;
}

// Function for level order traversal
void levelOrder(Employee* root) {
    if (root == NULL) {
        return;
    }
    queue<Employee*> q;
    q.push(root);

    while (!q.empty()) {
        Employee* current = q.front();
        cout << "Employee ID: " << current->employeeID
             << ", Name: " << current->name
             << ", Salary: " << current->salary
             << ", Department: " << current->department << endl;
        q.pop();

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Function to calculate the height of the tree
int height(Employee* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value (employee ID) in the tree
int findMin(Employee* node) {
    while (node->left) {
        node = node->left;
    }
    return node->employeeID;
}

// Function to find the maximum value (employee ID) in the tree
int findMax(Employee* node) {
    while (node->right) {
        node = node->right;
    }
    return node->employeeID;
}

// Main function
int main() {
    Employee* root = NULL;
    root = insert(root, 101, "Alice", 50000.0, "HR");
    root = insert(root, 102, "Bob", 60000.0, "IT");
    root = insert(root, 103, "Charlie", 55000.0, "Finance");
    root = insert(root, 104, "David", 62000.0, "Marketing");
    root = insert(root, 201, "Eve", 51000.0, "HR");
    root = insert(root, 202, "Frank", 59000.0, "IT");
    root = insert(root, 203, "Grace", 60000.0, "Finance");

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

// In-order traversal
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

// Post-order traversal
    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

// Level-order traversal
    cout << "Level-order traversal: ";
    levelOrder(root);
    cout << endl;

    int treeHeight = height(root);
    cout << "Height of the tree: " << treeHeight << endl;
    int minEmployeeID = findMin(root);
    cout << "Minimum Employee ID: " << minEmployeeID << endl;

    int maxEmployeeID = findMax(root);
    cout << "Maximum Employee ID: " << maxEmployeeID << endl;

}
