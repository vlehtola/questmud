inherit "obj/monster";
int pouch,vial;
object ob;

reset(arg) {
  pouch -= pouch / 10;
  vial -= vial / 10;
  ::reset(arg);
  if(arg) { return; }
  set_name("zinuq");
  set_level(75);
  set_short("Zinuq the witch shopkeeper.");
  set_long("This old women looks somehow strange. Dressed completely in grey\n"+
           "and wearing tall hat on his head. She has a wise look on his face\n"+
           "and she must be hundred yeards old but still looking so beautifull.\n");
  set_skill("herbalist knowledge", random(200));
  set_log();
  set_gender(1);
  set_race("dryad");
  set_special(25);
  pouch = 50;
  vial = 5;
  ob = clone_object("/wizards/neophyte/swamp/eq.c");
  move_object(ob, this_object());
  init_command("wear guards");
}

init() {
  ::init();
  add_action("show", "show");
  add_action("buy", "buy");
}

show() {
  write("The Zinuq is currently selling:\n");
  write("pouch            "+pouch+" copper coins\n");
  write("vial             "+vial+"  copper coins\n");
  write("\n");
  return 1;
}

buy(str) {
  int num;
  if(str=="pouch") {
        num = pouch;
        if(!random(5)) { pouch += 1; }
  } else if(str=="vial") {
        num = vial;
        str = "empty_potion";
        if(!random(3)) { vial += 1; }
  }
  if(!num) {
    write("Zinuq says: There are no "+str+" for sale currently.\n");
    return 1;
  }
  if(this_player()->query_money(2) < num) {
    write("Zinuq says: Sorry, but you don't have enough copper coins.\n");
    return 1;
  }
  this_player()->reduce_money(num,2);
  move_object(clone_object("/guilds/witch/obj/"+str), this_player());
  write("You buy one "+str+" with "+num+" coins.\n");
  say(this_player()->query_name()+" buys something.\n", this_player());
  return 1;
}

special_move() {
        object ob,ob1,tgt;
        int i;
        i = this_object()->query_skills("herbalist knowledge");
        ob1 = this_object()->query_attack();
        tgt = ob1->query_name();
        tell_object(ob1, "Zinuq throws vial at you!\n");
        ob = clone_object("/guilds/witch/potions/"+({ "fire_single", "cold_single", "electric_single", "poison", "curse", "stun",})[random(5)]+".c");
        ob->start(i, ob1);
        return 1;
}
