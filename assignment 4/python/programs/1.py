def time_diff():
    start_time = input("Enter the start time in the format hr-min-sec: ")
    end_time = input("Enter the end time in the format hr-min-sec: ")
    start_hr, start_min, start_sec = map(int, start_time.split("-"))
    end_hr, end_min, end_sec = map(int, end_time.split("-"))
    start_time_in_sec = start_hr * 3600 + start_min * 60 + start_sec
    end_time_in_sec = end_hr * 3600 + end_min * 60 + end_sec
    return end_time_in_sec - start_time_in_sec


print(time_diff())
