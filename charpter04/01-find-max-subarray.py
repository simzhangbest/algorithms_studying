'''
@Description: In User Settings Edit
@Author: your name
@Date: 2019-10-14 10:45:05
@LastEditTime: 2019-10-14 10:45:05
@LastEditors: your name
'''
def find_maximum_subarray(nums, low, high):
    if low == high:
        return {"low": low, "high": high, "sum": nums[low]}
    else:
        mid = int((low + high) / 2)
        left_result = find_maximum_subarray(nums, low, mid)
        right_result = find_maximum_subarray(nums, mid + 1, high)
        cross_result = find_max_crossing_subarray(nums, low, mid, high)
        if left_result["sum"] >= right_result["sum"] and left_result["sum"] >= cross_result["sum"]:
            return left_result
        else:
            if right_result["sum"] >= left_result["sum"] and right_result["sum"] >= cross_result["sum"]:
                return right_result
            else:
                return cross_result


def find_max_crossing_subarray(nums, low, mid, high):
    left_sum = -float('inf')
    total = 0
    max_left = mid
    for i in range(mid, low-1, -1):
        total += nums[i]
        if total > left_sum:
            left_sum = total
            max_left = i

    rigth_sum = -float('inf')
    total = 0
    max_right = mid + 1
    for j in range(mid+1, high+1):
        total += nums[j]
        if total > rigth_sum:
            rigth_sum = total
            max_right = j

    return {"low": max_left, "high": max_right, "sum": left_sum + rigth_sum}


if __name__ == "__main__":
    numss = [-1, 5, 6, 9, 10, -9, -8, 100, -200]
    result = find_maximum_subarray(numss, 0, len(numss)-1)
    print(result)