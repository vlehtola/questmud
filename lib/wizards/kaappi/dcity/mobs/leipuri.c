inherit "obj/monster";
int bread,ham,cheese;
int a = 0;

reset(arg) {
  cheese -= cheese / 10;
  bread -= bread / 20;
  ham -= ham / 30;

  ::reset(arg);
  if(arg) { return; }
  set_name("gimim");
  set_alias("baker");
  set_level(80);
  set_race("dwarf");
  set_log();
  set_str(query_str()*2);
  set_short("Gimim, The baker of Amaranthgard");
  set_long("Gimim the baker is here selling food. He is very short\n"+
           "and very fat. Due to his physical appearance,\n"+
           "one could easily assume that he enjoys his own food.\n"+
           "See 'list' if you are intressed about the prices.\n");
  cheese = 10;
  bread = 20;
  ham = 30;
}

init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}

list() {
  write("\n");
  write("The baker is currently selling:\n");
  write("Ham            "+ham+" copper coins\n");
  write("Cheese         "+cheese+" copper coins\n");
  write("Bread          "+bread+" copper coins\n");
  write("\n");
  return 1;
}

buy(str) {
  int num;
  if(str=="bread") {
        num = bread;
        if(!random(5)) { bread += 1; }
  } else if(str=="cheese") {
        num = cheese;
        if(!random(4)) { cheese += 1; }
  } else if(str=="ham") {
        num = ham;
        if(!random(3)) { ham += 1; }
  }
  if(!num) {
    write("The baker says: There are no "+str+" for sale currently.\n");
    return 1;
  }
  if(this_player()->query_money(2) < num) {
    write("The baker says: Sorry, but you don't have enough copper coins.\n");
    return 1;
  }
  this_player()->reduce_money(num,2);
  move_object(clone_object("/world/objects/"+str), this_player());
  write("You buy one "+str+" with "+num+" coins.\n");
  say(this_player()->query_name()+" buys some food.\n", this_player());
  return 1;
}


catch_tell(str) {
  string tmp1,tmp2;
  object ob;
  ::catch_tell(str);
  if (sscanf(str, "%s gives %s to you.", tmp1,tmp2) == 2) {
  ob = present("head", this_object());
  if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
  destruct(ob);
  write("Thur says: 'Thank you. Now my food ingredients are in safe again.'\n");
  this_player()->set_quest("Help the Baker in Amaranthgard");
  
return 1;    }
 }
}
