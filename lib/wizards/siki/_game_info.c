
status cmd_game_info(string str) {
int i;
object *ob;
ob = users();
if(!str) { write("Usage: game-info <inform>\n"); return 1; }
if(str == "last") { tail("/log/SHOUT"); return 1; }
if(this_player()->query_wiz() < 2) {
  write("You can't use this command yeat!\n");
  return 1;
}
for(i=0;i<sizeof(ob);i++) {
tell_object(ob[i], this_player()->query_name()+" <game-info> "+str+".\n");
}
write_file("/log/INFO","["+ctime()[11..15]+"] - "+this_player()->query_name()+": "+str+"\n");
return 0;
}

