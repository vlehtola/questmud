inherit "obj/monster";
 
int a=0,b=0,c=0,d=0,e=0;
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(29+random(4));
    set_experience(696969);
    set_name("jenna");
    set_alias("alchemist");
    set_short("Jenna, the alchemists daughter");
    set_long("The daughter of the old alchemist Efraim En-Dor stands here.\n"+
             "She has deep brown eyes, and auburn hair. Many men have fallen\n"+
             "for her, and you can well understand why. The ressemblence with\n"+
             "her father is almost non existant.\n");
    set_race("human");
    set_gender(2);
    set_al(50);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Jenna says: 'May I help you?'\n";
        chat_str[1] =
          "Jenna hums a little tune.\n";
        chat_str[2] =
          "Jenna runs her fingers through her hair.\n";
 
   }
 if (!a_chat_str) {   
        a_chat_str = allocate(1);
        a_chat_str[0] = "Jenna shouts: 'What are you doing?'\n";
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
{ say("Jenna says: 'Here, i made a nice necklace out of those. Use it well, it is very fragile'.\n");
  a=0; b=0; c=0; d=0; e=0;
  move_object(clone_object("/wizards/walla/jericho/stuph/objX"),
              this_player());
tell_room(environment(this_object()), "As Jenna gives the necklace, a roaring shout\n"+
                                      "can be heard\n");
shout("Leb Kamar shouts: So, my alchemist has betrayed me! Now she must DIE!\n");
ob = all_inventory(environment(this_object()));
     for(i=0; i < sizeof(ob) ; i++) {
       if(living(ob[i]))
        ob[i]->hit_with_spell(400, "fire");
     }
call_out("jenna_rips", 1);


 "/wizards/walla/jericho/rooms/leblair/entrance"->set_done("kelju");
}
else {  say("Jenna says: 'Thanks for that item'.\n"); }
  destruct(item_ob);
  }
}
jenna_rips() {
  tell_room(environment(this_object()), "Jenna falls down, and draws her last breath.\n");

  this_object()->death();
}
