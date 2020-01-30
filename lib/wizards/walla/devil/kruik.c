inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(100+random(20));
    set_name("Mysterious man");
    set_alias("man");
    set_race("human");
    set_short("Mysterious man waiting here something");
    set_long("This man is just an ordinary gravestone maker, which\n"+
                      "is lost one piece of its most important gravestone.\n" +
                       "Man is wearing old looking clothes, like its life depends\n" +
                        "on that piece of gravestone\n");    
    set_al(100);
    set_aggressive(0);

   catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("stone", this_object()); 
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
    destruct(ob);
    write("Man says 'Thank you my fellow, now I can make my gravestone.\n");
    write("Man says 'Take this amulet as a reward by returning my piece of gravestone.\n");
    move_object(clone_object("/wizards/devil/area/equ/qamulet.c"), this_player());
    this_player()->set_quest("Kill the evil emperor");
  }
 }
}
