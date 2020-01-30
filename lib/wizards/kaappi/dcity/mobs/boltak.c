inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(15+random(3));
  set_name("boltak");
  set_race("dwarf");
  set_alias("child");
  set_gender(1);
  set_short("Boltak, the dwarven child");
  set_long("This child differs from others.\n"+
           "He is somewhat bigger than others and it\n"+
           "seems that he is the boss of these kids.\n"+
           "At this moment he looks very angry and\n"+
           "he is yelling to other childs.\n");
  set_al(40);

  set_aggressive(0);

}
catch_tell(str) {
     string tmp1,tmp2;
     object ob;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1,tmp2) == 2) {
    ob = present("doll", this_object());
  if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
  destruct(ob);
  write("Boltak smiles and says:'Wow, You find it!'\n");
  this_player()->set_quest("Conciliate Boltak");
  call_out("delay_dest", 0, this_object());
}
}
return 1;
}
