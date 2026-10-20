#include <iostream>
using namespace std;

// 1. Initializing Arrays
// Stored on stack
// int arr[5];
// int nums[5] = { 1, 3, 4, 7, 5 };
// Stored on heap (requires manual memory release)
// int* arr1 = new int[5];
// int* nums1 = new int[5] { 1, 3, 4, 7, 5 };

// 2. Accessing Elements
/* --> Formula pic is in the root folder <--
Array elements are stored in contiguous memory space, which means calculating the memory address
of array elements is very easy. Given the array’s memory address (the memory address of the first
element) and an element’s index, we can use the formula showninFigure 4-2to calculate the element’s
memory address and directly access that element.
*/
int randomAccess(int *nums, int size)
{
    // Randomly select a number from interval [0, size]
    int randomIndex = rand() % size;
    // Retrieve and return the random element
    int randomNum = nums[randomIndex];
    return randomNum;
}

// 3. Inserting Elements
/*
Array elements are stored “tightly adjacent” in memory, with no space between them to store any ad
ditional data. As shown in Figure 4-3, if we want to insert an element in the middle of an array, we
need to shift all elements after that position backward by one position, and then assign the value to
that index.
*/
void insert(int *nums, int size, int num, int index)
{
    // Move all the elements at and after index index backward by one position
    for (int i = size - 1; i > index; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[index] = num; // insert the element at index index
}

// 4. Removing elements
/*
to delete the element at index 𝑖, we need to shift all elements after
index 𝑖 forward by one position.
*/
// Remove the element at index index
void remove(int *nums, int size, int index)
{
    //  Move all elements after index index forward by one position
    for (int i = index; i < size - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
}

/**
 * Overall, array insertion and deletion operations have the following drawbacks:
• High time complexity: The average time complexity for both insertion and deletion in arrays is
𝑂(𝑛), where 𝑛 is the length of the array.
• Loss of elements: Since the length of an array is immutable, after inserting an element, elements
that exceed the array’s length will be lost.
• Memory waste: We can initialize a relatively long array and only use the front portion, so that
wheninserting data, the lost elements at the endare“meaningless”, but this causes some memory
space to be wasted.
 */

//  5. Traversing Arrays
int traverse(int *nums, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count += nums[i];
    }
    return count;
}

// 6. Finding Elements
/*
Finding a specified element in an array requires traversing the array and checking whether thee lement
value matches in each iteration; if it matches, output the corresponding index.
Since an array is a linear datastructure, the below search operation is called a “linearsearch”.
*/
// Find specified element in the array
int find(int *nums, int size, int target){
    for(int i=0; i<size; i++){
        if(nums[i] == target)
            return i;
    }
    return -1;
}

// 7. Expanding Arrays
/**
 * In complex system environments, programs cannot guarantee that the memory space after an array is
available, making it unsafe to expand the array’s capacity. Therefore, in most programming languages,
the length of an array is immutable.
If we want to expand an array, we need to create a new, larger array and then copy the original array
elements to the new array one by one. This is an 𝑂(𝑛) operation,which is very time-consuming when
the array is large. The code is shown below:
 */
int *extend(int *nums, int size, int enlarge){
    // Initialize an array with extended length
    int *res = new int[size + enlarge];
    // Copy all elements from the original array to the new array
    for(int i=0; i<size; i++){
        res[i] = nums[i];
    }
    // free memory
    delete[] nums;
    // return the extended new array
    return res;
}

// Common Array Operations
int main()
{

    int array[] = {2, 3, 6, 7, 8};
    int size = 5;
    int num = 100;

    // 3. Inserting Element
    // insert(array, size, num, 2);
    // cout << "After Inserting element in the array: ";
    // for(int val: array)
    //     cout << val << " ";

    // 4. Removing Element
    // remove(array, size, 0);
    // cout << "After removing the element from the array: ";
    // for(int val: array){
    //     cout << val << " ";
    // }

    // 5. Traversing Arrays
    // int result =  traverse(array, size);
    // cout << "Traverse Array: " << result << endl;

    // 6. Finding Element
    // int target = 3;
    // int result = find(array, size, target);
    // cout << "The element found in the array at index: " << result << endl;

    // 7. Extended Array
    int *nums = new int[3]{1, 2, 3};
    int *result = extend(nums, 3, 5);

   cout << "After Extend: ";
    for(int i = 0; i < 5; i++)
        cout << result[i] << " ";
    cout << "\n";

    return 0;
}
