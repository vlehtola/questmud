// Copied from gameinfo.c - Nalle - summer '04

status cmd_wizinfo(string str) 
{
 if(!str) { write("Usage: wizinfo <inform>\n"); return 1; }

 if(str == "last") { tail("/log/WIZINFO"); return 1; }

 if(this_player()->query_wiz() < 2)
  {
   write("You can't use this command yet!\n");
   return 1;
  }

 "/daemons/channel_d"->send_to_channel("wiz", "Game info from "+this_player()->query_name()+": "+str+"\n", this_player());
 write_file("/log/WIZINFO","["+ctime()[4..9]+"] - "+this_player()->query_name()+": "+str+"\n");
 return 1;
}

