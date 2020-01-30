 /* CMD HANDLER BY CENDOR */

status cmd_handler(string str) {
  string cmd,command,file;

  cmd = query_verb();
  command = "cmd_"+cmd;

if(this_player() -> query_name() == "cendor") {
  file = "/wizards/cendor/cmds/_" + cmd + ".c";
  if(file_size(file) > 0) 
   return (int)call_other(file, command, str);
}
if((int)this_object() -> query_wiz()) {
  file = "/cmds/wiz/" + "_" + cmd + ".c";
 if(file_size(file) > 0)
  return (int)call_other(file, command, str);
}
if((int)this_object() -> query_wiz() >= 3) {
  file = "/cmds/adm/" + cmd + ".c";
 if(file_size(file) > 0)
  return (int)call_other(file, command, str);
}
 file = "/cmds/std/_" + cmd + ".c";
if(file_size(file) > 0)
  return (int)call_other(file, command, str);
}
