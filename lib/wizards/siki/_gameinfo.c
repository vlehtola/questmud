
status cmd_gameinfo(string str) {
if(!str) { write("Usage: gameinfo <inform>\n"); return 1; }
if(str == "last") { tail("/log/SHOUT"); return 1; }
if(this_player()->query_wiz() < 2) {
  write("You can't use this command yeat!\n");
  return 1;
}
"/daemons/channel_d"->send_to_channel("inform", "Game info from "+this_player()->query_name()+": "+str+".\n", this_player());
write_file("/log/INFO","["+ctime()[11..15]+"] - "+this_player()->query_name()+": "+str+"\n");
return 1;
}

