query_invalid() {
  string tmp, str;
  str = file_name(environment(this_player()));
  if(sscanf(str, "/world/%s", tmp) == 1 ||
     str == "/room/bank" ||
     str == "/room/locker") {

    if(sscanf(str, "/world/out/%s", tmp) == 1) return 0;

    write("Your spell fizzled due some external force.\n");
    return 1;
  }
}
