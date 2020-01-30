init() {
  add_action("remdir", "remdir");
  add_action("list", "list");
}

list() {
  string list, dir;
  int i;
  dir = "/wizards/archsin/test/delme/";

  list = get_dir(dir);
  for(i=0; i<sizeof(list); i++) {
    rm(dir+list[i]);
  }
  rmdir(dir);
  return list;
}

remdir() {
  if(rmdir("/wizards/archsin/test/delme")) write("success.\n");
  else write("cant do\n");
  return 1;
}
