inherit "obj/monster";  
int doughnut,steak,chops;
 
reset(arg) {
  doughnut -= doughnut / 21;
  steak -= steak / 121;
  chops -= chops / 69;
  ::reset(arg);
  if(arg) { return; }
  set_name("Glen");
  set_level(30);
  set_short("Glen, the Donut seller at Stan Mikita's");
  set_long("Northam is here, selling Trebor's foods.\n" +
        "Type 'list' to see what he sells, and at what prices.\n");
  doughnut = 14;
  steak = 21;
 steak = 33;                 
}
 
init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}
 
list() {
  write("\n");
  write("Northam smiles and shows you the menu:\n");
  write("-----------------------------------------\n");
  write("A yumee donut  -  "+doughnut+" coins\n");
  write("A juicy steak   -   "+steak+" coins\n");
  write("Some lamb chops      -      "+chops+" coins\n");
 write("-----------------------------------------\n");                 
  write("\n");
return 1;
}
 
buy(str) {
  int num;
  if(str=="doughnut") {
        num = doughnut;
        if(!random(3)) { doughnut += 1; }
  } else if(str=="steak") {
        num = steak;
        if(!random(3)) { steak += 1; }
  } else if(str=="steak") {
        num = steak;
        if(!random(3)) { steak += 1; }
}                  
  if(!num) {
write("Northam states: We don't eat "+str+" in this part of the country.\n");
    return 1;
  }
  if(this_player()->query_money() < num) {
    write("Northam booms: I only accept cash.\n");
    return 1;
  }
  this_player()->add_money(-num);
  move_object(clone_object("/wizards/nalle/area/"+str), this_player());
  write("Northam hands you a "+str+" for "+num+" coins.\n");
  say(this_player()->query_name()+" buys a something to eat.\n", this_player());
  return 1;
}

