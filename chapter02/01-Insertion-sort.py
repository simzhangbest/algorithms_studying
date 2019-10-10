'''
@Description: In User Settings Edit
@Author: your name
@Date: 2019-10-10 14:59:32
@LastEditTime: 2019-10-10 16:59:59
@LastEditors: Please set LastEditors
'''


'''
@description: 
@param {type} 
@return: 
'''
def insertion_sort(collection):
    for loop_index in range(1, len(collection)):
        insertion_index = loop_index
        while (
            insertion_index > 0 
            and collection[insertion_index - 1] > collection[insertion_index]):
            (collection[insertion_index], collection[insertion_index-1]) = (collection[insertion_index - 1], collection[insertion_index])
            insertion_index -= 1
    return collection




if __name__ == "__main__":
    user_input = input("Enter numbers separated by a comma:\n").strip()
    unsorted = [int(item) for item in user_input.split(",")]
    print(insertion_sort(unsorted))