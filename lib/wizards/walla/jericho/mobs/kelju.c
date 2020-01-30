inherit "obj/monster";
 
int a=0,b=0,c=0,d=0,e=0;

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(4+random(4));
    set_name("kelju");
    set_alias("kojootti");
    set_short("kelju k kojootti");
    set_long("There is not much to say about this remnant of a man.\n"+
             "Where he hasn't been beaten up, his skin is of a strange\n"+
             "brownish colour. He looks as if he hasn't had anything to\n"+
             "eat for a long time.\n");
    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Prisoner whispers faintly: 'please help me'.\n";
        chat_str[1] =
          "Prisoner begs you for something to eat.\n";
        chat_str[2] =
          "Prisoner begs you for water.\n";
        chat_str[3] = 
          "Prisoner whispers faintly: 'I know how to defeat Leb-kamar'.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Prisoner sighs: 'Now no one will know the secret'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);

}

catch_tell(str) {
    string giver,item,tmp,temp;
    object ob, item_ob;
    if (!str) return 1; 
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) return;
      item_ob = present("shard", this_object());
      if (!item_ob) return;

 
if(sscanf(file_name(item_ob),
   "/wizards/walla/jericho/stuph/obj1%s",temp)==1) a++; 
if(sscanf(file_name(item_ob),
   "/wizards/walla/jericho/stuph/obj2%s",temp)==1) b++; 
if(sscanf(file_name(item_ob),
   "/wizards/walla/jericho/stuph/obj3%s",temp)==1) c++; 
if(sscanf(file_name(item_ob),
   "/wizards/walla/jericho/stuph/obj4%s",temp)==1) d++; 
if(sscanf(file_name(item_ob),
   "/wizards/walla/jericho/stuph/obj5%s",temp)==1) e++; 

 say(file_name(item_ob)+" A== "+a+"\n");

if(a && b && c && d && e) 
{ say("Kelju sanoo: Kaikki o kasas, keijot! Tas potkuri sulle!\n"); 
  a=0; b=0; c=0; d=0; e=0; 
  move_object(clone_object("/wizards/walla/jericho/stuph/objX"),
              this_player());
 "/wizards/walla/jericho/rooms/leblair/entrance"->set_done("kelju");
}
else {  say("Kelju whines: 'Thanks for that potkuri'\n"); }
  destruct(item_ob);
  }
}

