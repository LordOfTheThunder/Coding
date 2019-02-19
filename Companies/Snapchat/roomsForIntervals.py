# Company: Snapchat
# Question: Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.
# Example: For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
"""
"""
# Solution: Sort start and end times and iterate over them

def roomsForIntervals(intervals):
    start_times = [a[0] for a in intervals]
    end_times = [a[1] for a in intervals]
    start_times.sort()
    end_times.sort()
    start_ptr = end_ptr = rooms = 0
    while start_ptr < len(start_times) and end_ptr < len(end_times):
        if start_times[start_ptr] < end_times[end_ptr]:
            rooms += 1
            start_ptr += 1
            continue
        else:
            rooms -= 1
            end_ptr += 1
    return rooms


if __name__ == "__main__":
    print(roomsForIntervals([(30, 75), (0, 50), (60, 150)]))
    pass
