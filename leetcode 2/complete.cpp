#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;

//------------STACK-QUEUE---------------
//1. MAXIMUM NESTING DEPTH OF PARANTHESES
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
int maxDepth(string s) {
    int rez = 0, depth = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            rez = max(rez, ++depth);
        }
        else if(c==')'){
            --depth;
        }
    }
    return rez;
}

//2. REMOVE OUTERMOST PARANTHESES
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
string removeOuterParentheses(string s) {
    string ans;
    int numerues = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(') {
            ++numerues;
        }
        if (numerues > 1) {
            ans.push_back(c);
        }
        if (c == ')') {
            --numerues;
        }
    }
    return ans;
}

//3. FINAL PRICES WITH A SPECIAL DISCOUNT
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
vector<int> finalPrices(vector<int>& prices) {
    stack<int> stk;
    vector<int> ans = prices;
    for (int i = 0; i < prices.size(); i++) {
        while (!stk.empty() && prices[stk.top()] >= prices[i]) {
            ans[stk.top()] -= prices[i];
            stk.pop();
        }
        stk.push(i);
    }

    return ans;
}

//4. NUMBER OF STUDENTS UNABLE TO EAT LUNCH
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int numerues[2] = {0}; 
    
    for (int i = 0; i < students.size(); ++i) {
        ++numerues[students[i]];
    }
    for (int i = 0; i < sandwiches.size(); ++i) {
        if (numerues[sandwiches[i]]-- == 0) {
            return numerues[sandwiches[i] ^ 1];
        }
    }
    return 0;
}

//5. NUMBER OF RECENT CALLS
//Kompleksiteti kohor - O(1)
//Kompleksiteti hapsinor - O(n)
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

//--------------BST-----------------
//6. SEARCH IN A BINARY SEARCH TREE
//Kompleksiteti kohor - O(logn) // kur eshte e pa balancuar O(n)
//Kompleksiteti hapsinor - O(logn) // kur eshte e pa balancuar O(n)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;
        return root->val < val ? searchBST(root->right, val)
                                : searchBST(root->left, val);
    } 

//7. CONVERT SORTED ARRAY TO BINARY SEARCH TREE
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> constructBST = [&](int start,
                                                         int end) -> TreeNode* {
            if (start > end) {
                return nullptr;
            }
            int mid = start + (end - start) / 2;
            TreeNode* leftSubtree = constructBST(start, mid - 1);
            TreeNode* rightSubtree = constructBST(mid + 1, end);
            return new TreeNode(nums[mid], leftSubtree, rightSubtree);
        };
        return constructBST(0, nums.size() - 1);
}

//8. TWO SUM IV - INPUT IS A BST
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
bool findTarget(TreeNode* root, int k) {
    vector<int> elements;
    stack<TreeNode*> stack;
    TreeNode* current = root;
    // In-order traversal to collect elements of the BST
    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        elements.push_back(current->val);
        current = current->right;
    }
    // Use two-pointer technique to find if there exist two numbers that sum up to k

    int left = 0;
    int right = elements.size() - 1;
    while (left < right) {
        int sum = elements[left] + elements[right];
        if (sum == k) {
            return true;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

//9. RANGE SUM OF BST
//Kompleksiteti kohor - O(logn) // kur eshte e pa balancuar O(n)
//Kompleksiteti hapsinor - O(logn) // kur eshte e pa balancuar O(n)
int rangeSumBST(TreeNode* root, int low, int high) {
        // Kontrollon nëse nyja aktuale është bosh kthen 0 si shumë e nën-pemës.
          if (!root)
              return 0; 
        
        // Kontrollon nëse vlera e nyjes është më e vogël se 'low'.
        // Nëse po, nuk ka nevojë të kërkohet në nën-pemën majtas pasi të gjitha vlerat do të jenë më të vogla.
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        
        // Kontrollon nëse vlera e nyjes është më e madhe se 'high'.
        // Nëse po, nuk ka nevojë të kërkohet në nën-pemën djathtas pasi të gjitha vlerat do të jenë më të mëdha.
        if (root->val > high) 
            return rangeSumBST(root->left, low, high);
        
        // Nëse vlera e nyjes është brenda intervalit [low, high], shto vlerën e nyjes në shumën totale,
        // dhe vazhdo të kërkosh në të dy nën-pemet (majtas dhe djathtas) për vlera të tjera që mund të jenë brenda intervalit.
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}

//10. INCREASING ORDER SEARCH TREE
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(logn) // kur eshte e pa balancuar O(n)
    void inorder(TreeNode* node, TreeNode*& curr) {
        // Kontrollon nëse nyja është bosh. Nëse po, kthehu.
        if (!node) return;
        
        inorder(node->left, curr);// Vizito nën-pemën e majtë parë. 
        node->left = nullptr; // Heq lidhjen e majtë të nyjes aktuale pasi ajo nuk është e nevojshme në pemën e re.
        curr->right = node;// Lidh nyjen aktuale me të djathtën e 'curr'.
        curr = node;  // Zhvendos 'curr' për të treguar te nyja e fundit e shtuar.
        inorder(node->right, curr); // Vizito nën-pemën e djathtë.
    }
    TreeNode* increasingBST(TreeNode* root) {
        // Krijon një nyje ndihmëse për të ndihmuar në rirenditjen.
        TreeNode* answer = new TreeNode(0); 
        // Përdor një pointer ndihmës për të mbajtur vendin aktual ku duhet të shtohet nyja e ardhshme.
        TreeNode* curr = answer;
        // Thirr funksionin ndihmës 'inorder' për të filluar rirenditjen.
        inorder(root, curr);
        // Kthen pemen e re që fillon nga nyja pas nyjes ndihmëse.
        return answer->right;
    }
    


//--------------LINKED LISTS---------------

//11. CONVERT BINARY NUMBER IN A LINKED LIST TO INTEGER
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
int getDecimalValue(ListNode* head) {
    int result = 0;
    while (head != nullptr) { 
        result = result * 2 + head->val;
        head = head->next;
    }
    return result;
}
//12. MIDDLE OF THE LINKED LIST
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      //moves one node at a time
      fast = fast->next->next;
      //moves two nodes at a time
    }
    //kur pointeri fast mberrin ne fund te listes 
    //atehere slow do jete ne fund te listes

    return slow;
}

//13. REVERSE LINKED LISTS
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
        
    while (current != nullptr) {
        ListNode* nextNode = current->next; // Save next node
        current->next = prev;              // Reverse the link
        prev = current;                    // Move prev to current node
        current = nextNode;                // Move to the next node
    }
        
    return prev; // New head of the reversed list
}

//14. MERGE TWO SORTED LISTS
//Kompleksiteti kohor - O(m+n)
//Kompleksiteti hapsinor - O(1)
struct ListNode1 {
    int val;
    ListNode1* next;
    ListNode1() : val(0), next(nullptr) {}
    ListNode1(int x) : val(x), next(nullptr) {}
    ListNode1(int x, ListNode1* next) : val(x), next(next){}
};
ListNode1* mergeTwoLists(ListNode1* list1, ListNode1* list2) {
    ListNode1 placeholder; // Placeholder node to simplify merging
    ListNode1* tail =
        &placeholder; // Pointer to the last node of the merged list

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append any remaining nodes from list1 or list2
    if (list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return placeholder.next; // Head of the merged list
}

//15. INTERSECTION OF TWO LINKED LISTS
//Kompleksiteti kohor - O(m+n) //gjithmone
//Kompleksiteti hapsinor - O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode* currA = headA;
    ListNode* currB = headB;

    // Traverse both lists until they intersect or reach the end
    while (currA != currB) {
        // Move pointers to the next node, if available
        currA = currA ? currA->next : headB;
        currB = currB ? currB->next : headA;
    }

    // Return the intersection node or nullptr if no intersection
    return currA;
}

//---------------HASH TABLES----------------
//16. PERMUTATION DIFFERENCE BETWEEN TWO STRINGS
//Kompleksiteti kohor - O(s+t)
//Kompleksiteti hapsinor - O(s)
int findPermutationDifference(string s, string t) {
    // Create a hash table to store the last index of each character in s
    unordered_map<char, int> lastIndex;

    // Populate the hash table with the last index of characters in s
    for (int i = 0; i < s.length(); ++i) {
        lastIndex[s[i]] = i;
    }

    // Calculate the permutation difference
    int difference = 0;
    for (int i = 0; i < t.length(); ++i) {
        difference += abs(lastIndex[t[i]] - i);
    }

    return difference;
}

//17. HOW MANY NUMBERS ARE SMALLER THAN THE CURRENT NUMBER
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    // Initialize the result vector with the same size as nums
    vector<int> result(nums.size());

    // Initialize the prefix sum vector with 101 elements, all initialized to 0
    vector<int> prefixSum(101, 0);

    // Use an unordered map to count the frequency of each number in nums
    unordered_map<int, int> freqMap;

    // Count the frequency of each number in the array
    for (int i = 0; i < nums.size(); i++) {
        freqMap[nums[i]]++;
    }

    // Calculate the prefix sums to get the count of smaller numbers
    for (int i = 1; i <= 100; i++) {
        // prefixSum[i] stores the count of numbers less than or equal to i
        prefixSum[i] = prefixSum[i - 1] + freqMap[i - 1];
    }

    // Get the result for each element in the array
    for (int i = 0; i < nums.size(); i++) {
        // result[i] stores the count of numbers smaller than nums[i]
        result[i] = prefixSum[nums[i]];
    }

    return result;
}

//18. DECODE THE MESSAGE
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(1)
string decodeMessage(string key, string message) {
    // Create a substitution table
    unordered_map<char, char> substitutionTable;
    int index = 0;
    for (int i = 0; i < key.size(); ++i) {
        char c = key[i];
        if (c != ' ' && substitutionTable.find(c) == substitutionTable.end()) {
            substitutionTable[c] = 'a' + index++;
        }
    }

    // Align the substitution table with the regular English alphabet
    for (char c = 'a'; c <= 'z'; ++c) {
        if (substitutionTable.find(c) == substitutionTable.end()) {
            substitutionTable[c] = 'a' + index++;
        }
    }

    // Decode the message
    for (int i = 0; i < message.size(); ++i) {
        char& c = message[i];
        if (c != ' ') {
            c = substitutionTable[c];
        }
    }

    return message;
}

//19. NUMBER OF ARITHMETIC TRIPLETS
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
int arithmeticTriplets(vector<int>& nums, int diff) {
    // HashSet to store the elements we've seen so far
    unordered_set<int> seen;
    // Counter for the number of arithmetic triplets
    int count = 0;

    // Iterate through the nums array
    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i]; // Get the current number
        // Check if the required previous numbers exist in the set
        // We check if (num - diff) and (num - 2 * diff) are present in the set
        if (seen.find(num - diff) != seen.end() &&
            seen.find(num - 2 * diff) != seen.end()) {
            // If both conditions are met, it means we have found an arithmetic
            // triplet
            count++;
        }
        // Insert the current number into the set for future checks
        seen.insert(num);
    }

    // Return the total count of unique arithmetic triplets
    return count;
}

//20. COUNT NUMBER OF PAIRS WITH ABSOLUTE DIFFERENCE K
//Kompleksiteti kohor - O(n)
//Kompleksiteti hapsinor - O(n)
int countKDifference(vector<int>& nums, int k) {
    // HashMap to store the frequency of each element
    unordered_map<int, int> freq;
    // Counter for the number of valid pairs
    int count = 0;

    // Iterate through the nums array
    for (int i = 0; i < nums.size(); ++i) {
        // Check if (nums[i] + k) is in the map
        if (freq.find(nums[i] + k) != freq.end()) {
            count += freq[nums[i] + k];
        }
        // Check if (nums[i] - k) is in the map
        if (freq.find(nums[i] - k) != freq.end()) {
            count += freq[nums[i] - k];
        }
        // Increment the frequency of nums[i]
        freq[nums[i]]++;
    }

    return count;
}

int main(){
    int zgjidhje;
    cout<<"Zgjedh nje numer nga 1 deri ne 20:\n"<<endl;
    cout << "1. Maximum nesting depth of parentheses (1614)\n";
    cout << "2. Remove outermost parentheses (1021)\n";
    cout << "3. Final Prices With a Special Discount in a Shop (1475)\n";
    cout << "4. Number of Students Unable to Eat Lunch (1700)\n";
    cout << "5. Number of recent calls\n";
    cout << "6. Search in a binary search tree\n";
    cout << "7. Convert Sorted array to binary search tree\n";
    cout << "8. Two sum IV - Input is a BST\n";
    cout << "9. Range sum of BST\n";
    cout << "10. Increasing order search tree\n";
    cout << "11. Convert binary number in a linked list to an integer\n";
    cout << "12. Middle of linked list\n";
    cout << "13. Reverse linked list\n";
    cout << "14. Merge two sorted lists\n";
    cout << "15. Intersection of two linked lists\n";
    cout << "16. Permutation difference between two strings\n";
    cout << "17. How many numbers are smaller than the current number\n";
    cout << "18. Decode the message\n";
    cout << "19. Number of arithmetic triplets\n";
    cout << "20. Count number of pairs with absolute difference K\n";

    cout << "Sheno zgjidhjen: ";
    cin>>zgjidhje;

    switch (zgjidhje)
    {
        //STACK-QUEUE
        case 1: {//maximum nesting depth of parantheses
            string s1 = "(1+(2*3)+((8)/4))+1";
            cout << maxDepth(s1) << endl;
            break;
        }
        case 2:{ //remove outermost parantheses
            string s2;
            cout<<"Sheno nje string me kllapa ashtu qe te heqim kllapat e jashtme: ";
            cin>>s2;
            cout << "\nRezultati: " << removeOuterParentheses(s2) << endl;
            break;
        }
        case 3: {//final prices with a special discount
            vector<int> cmimet = {8, 4, 6, 2, 3};
            vector<int> cmimet_perfundimtare = finalPrices(cmimet);

            cout << "Çmimet përfundimtare janë: ";
            for (int i = 0; i < cmimet_perfundimtare.size(); i++) {
                cout << cmimet_perfundimtare[i] << " ";
            }
            cout << endl;
            break;}

        case 4:{ //number of students unable to eat lunch
            vector<int> students = {0, 1, 0, 1, 1};
            vector<int> sandwiches = {0, 1, 1};
            cout << "Numri i studenteve qe nuk munden te hane: " << countStudents(students, sandwiches) << endl;
            break;}

        case 5: {//Number of recent calls
            RecentCounter sol;
            cout << sol.ping(1) << endl;
            cout << sol.ping(100) << endl;
            cout << sol.ping(3001) << endl;
            cout << sol.ping(3002) << endl;
            break;}
        //BINARY SEARCH TREE

        case 6:{// search in a BST
            TreeNode* root = new TreeNode(4);
            root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
            root->right = new TreeNode(7);
            int searchValue;  
            cout << "Sheno vleren per kerkim ne BST: ";
            cin >> searchValue;

            TreeNode *result = searchBST(root, searchValue);
            if (result) {
                cout << "Vlera " << searchValue << " u gjet ne BST. Vlera e nyjes: " << result->val << endl;
            } else {
                cout << "Vlera  " << searchValue << " nuk u gjet ne BST." << endl;
            }
            break;
        }
        case 7:{//convert sorted array to binary search tree
            vector<int> nums = {-10, -3, 0, 5, 9}; 
            TreeNode* root = sortedArrayToBST(nums);
            if (root != nullptr) {
                cout << "Rrenja e BST: " << root->val << endl;
            } else {
                cout << "Asnje peme e krijuar." << endl;
            }
            break;
        }
        case 8: {//Two sum IV - Input is a BST
            TreeNode* root = new TreeNode(5);
            root->left = new TreeNode(3);
            root->right = new TreeNode(6);
            root->left->left = new TreeNode(2);
            root->left->right = new TreeNode(4);
            root->left->left->left = new TreeNode(1);
            root->right->right = new TreeNode(8);
            root->right->right->left = new TreeNode(7);
            root->right->right->right = new TreeNode(9);
            int k = 9;
            cout << (findTarget(root, k) ? "true" : "false") << endl;
            break;
        }
        case 9: {//Range Sum of BST
            TreeNode* root = new TreeNode(10);
            root->left = new TreeNode(5);
            root->right = new TreeNode(15);
            root->left->left = new TreeNode(3);
            root->left->right = new TreeNode(7);
            root->right->right = new TreeNode(18);
            int low = 7, high = 15;
            cout << rangeSumBST(root, low, high) << endl;
            break;
        }
        case 10: { // Increasing order search tree
            // Create the root of the tree with value 5
            TreeNode* root = new TreeNode(5);
            // Create and attach the left and right children of the root
            root->left = new TreeNode(3);
            root->right = new TreeNode(6);
            // Create and attach the left and right children of the node with value 3
            root->left->left = new TreeNode(2);
            root->left->right = new TreeNode(4);
            // Create and attach the left child of the node with value 2
            root->left->left->left = new TreeNode(1);
            // Create and attach the right child of the node with value 6
            root->right->right = new TreeNode(8);
            // Create and attach the left and right children of the node with value 8
            root->right->right->left = new TreeNode(7);
            root->right->right->right = new TreeNode(9);
            // Call the function to rearrange the tree in increasing order
            TreeNode* result = increasingBST(root);
            // Print the values of the resulting tree in a single line
            while (result) {
                cout << result->val << " ";
                result = result->right;
            }
            cout << endl;
            break;
        }
        //---LINKED LISTS----
        case 11: { //Convert binary number in a linked list to an integer
            ListNode* head = new ListNode(1);
            head->next = new ListNode(0);
            head->next->next = new ListNode(1);
            cout << getDecimalValue(head) << endl;
            break;
        }
        case 12: { //Middle of linked list
            ListNode* head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            ListNode* result = middleNode(head);
            cout << result->val << endl;
            break;
        }
        case 13: { //Reverse linked list
            ListNode* head = new ListNode(1);
            head->next = new ListNode(2);
            head->next->next = new ListNode(3);
            head->next->next->next = new ListNode(4);
            head->next->next->next->next = new ListNode(5);
            ListNode* result = reverseList(head);
            while (result) {
                cout << result->val << " ";
                result = result->next;
            }
            cout << endl;
            break;
        }
        case 14: { //Merge two sorted lists
            // Define the nodes statically
            ListNode1 l1(1);
            l1.next = new ListNode1(2);
            l1.next->next = new ListNode1(4);

            ListNode1 l2(1);
            l2.next = new ListNode1(3);
            l2.next->next = new ListNode1(4);

            // Call mergeTwoLists with the statically defined nodes
            ListNode1* result = mergeTwoLists(&l1, &l2);

            // Print the merged list
            ListNode1* curr = result;
            while (curr != nullptr) {
                cout << curr->val << " ";
                curr = curr->next;
            }
            cout << endl;


            break;
        }
        case 15: { // Intersection of two linked lists
            // Create two sorted lists
            ListNode1* list1 = new ListNode1(1);
            list1->next = new ListNode1(3);
            list1->next->next = new ListNode1(5);

            ListNode1* list2 = new ListNode1(2);
            list2->next = new ListNode1(4);
            list2->next->next = new ListNode1(6);

            // Merge the two lists
            ListNode1* mergedList = mergeTwoLists(list1, list2);

            // Print the merged list
            while (mergedList != nullptr) {
                cout << mergedList->val << " ";
                mergedList = mergedList->next;
            }
            cout << endl;
            break;
        }
        //-----HASH TABLES------
        case 16: { //Permutation difference between two strings
            string s = "abcde";
            string t = "edcba";
            int result = findPermutationDifference(s, t);
            cout << "Permutation difference: " << result << endl;
            break;
        }
        case 17: { //How many numbers are smaller than the current number
            vector<int> nums = {8, 1, 2, 2, 3};
            vector<int> result = smallerNumbersThanCurrent(nums);
            for (int num : result) cout << num << " ";
            cout << endl;
            break;
        }
        case 18: { //Decode the message
            string key = "the quick brown fox jumps over the lazy dog";
            string message = "vkbs bs t suepuv";
            cout << decodeMessage(key, message) << endl;
            break;
        }
        case 19: { //Number of arithmetic triplets
            vector<int> nums = {0, 1, 4, 6, 7, 10};
            int diff = 3;
            cout << arithmeticTriplets(nums, diff) << endl;
            break;
        }
        case 20: { //Count number of pairs with absolute difference K
            vector<int> nums = {1, 2, 2, 1};
            int k = 1;
            cout << countKDifference(nums, k) << endl;
            break;
        }

        //DEFAULT
        default:{
            cout<<"Funksion i panjohur"<<endl;
            break;
        }
    }
    return 0;
}
