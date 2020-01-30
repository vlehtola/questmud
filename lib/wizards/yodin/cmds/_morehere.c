cmd_morehere() {
  string file;

file = file_name(environment(this_player()))+".c";
write(read_file(file));
return 1;
}
