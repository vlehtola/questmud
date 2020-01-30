inherit "obj/monster";
string chat_str;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(40 + random(5));
  set_name("thur");
  set_race("dwarf");
  set_alias("historian");
  set_gender(1);
  set_short("Thur, the historian");
  set_long("A very old looking dwarf. He is sitting on\n"+
           "his chair and his hands are shaking as he\n"+
           "tries to write something on the paper.\n");
  set_al(40);
 set_al_aggr(200);

if (!chat_str) {
   chat_str = allocate(3);
   chat_str[0] = "Thur says: 'My job here is almost done..'\n";
   chat_str[1] = "Thur says: '..but now one piece of my notes has lost.'\n";
   chat_str[2] = "Thur says: 'If I could find it from somewhere, then I can rest in peace..'\n";
}
load_chat(2, chat_str);
}
catch_tell(str) {
     string tmp1,tmp2;
     object ob;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1,tmp2) == 2) {
    ob = present("paper", this_object());
  if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
  destruct(ob);
   write("Thur says: 'Thank you. Now I can finish the history of Amaranthgard.'\n");
  this_player()->set_quest("Help the historian");
  call_out("delay_dest", 0, this_object() );
  }
 }
}

int delay_dest(object obj) {
destruct(obj);
return 1;
}
