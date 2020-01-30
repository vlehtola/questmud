inherit "obj/monster";
int minorp,lesserp,greaterp;
 
reset(arg) {
  1 -= minorp / 1000;
  2 -= lesserp / 2000;
  3 -= greaterp / 3000;
  ::reset(arg);
  if(arg) { return; }
  set_name("woman");
  set_level(100);
  set_short("Old gypsy woman is selling her potions here.");
  set_long("Woman is here, selling her potions.\n" +
        "Type 'list' to see what she sells, and at what prices.\n");
  1 = 1000;
  2 = 2000;
  3 = 3000;
}
 
init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}
 
list() {
  write("\n");
  write("Woman grins and shows you the menu:\n");
  write("--------------------------------------------------\n");
  write("1. A minor healing potion.    -   "+minorp+" coins\n");
  write("2. A lesser healing potion.   -  "+lesserp+" coins\n");
  write("3. A greater healing potion.  - "+greaterp+" coins\n");
  write("--------------------------------------------------\n");
  write("\n");
return 1;
}
 
buy(str) {
  int num;
  if(str=="1") {
        num = minorp;
        if(!random(3)) { minorp += 1; }
  } else if(str=="2") {
        num = lesserp;
        if(!random(3)) { lesserp += 1; }
  } else if(str=="3") {
        num = greaterp;
        if(!random(3)) { greaterp += 1; }
  }
  if(!num) {
write("Woman states: I don't have "+str+" in my inventory.\n");
    return 1;
  }
  if(this_player()->query_money() < num) {
    write("Woman shrieks: I only accept cash.\n");
    return 1;
  }
  this_player()->add_money(-num);
  move_object(clone_object("/wizards/morgoth/event/"+str), this_player());
  write("Woman hands you a "+str+" for "+num+" coins.\n");
  say(this_player()->query_name()+" buys a healing potion.\n", 
this_player());
  return 1;
}
