inherit "obj/monster";
int sandwich,noodles,boar;

reset(arg) {
  sandwich -= sandwich / 14;
  noodles -= noodles / 21;
  boar -= boar / 33;
  ::reset(arg);
  if(arg) { return; }
  set_name("northam");
  set_level(30);
  set_short("Northam, the cook's assistant");
  set_long("Northam is here, selling Trebor's foods.\n" +
        "Type 'list' to see what he sells, and at what prices.\n");
  sandwich = 14;
  noodles = 21;
  boar = 33;
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
  write("A seaweed Sandwich  -  "+sandwich+" coins\n");
  write("A bowl of Noodles   -   "+noodles+" coins\n");
  write("A roasted Boar      -      "+boar+" coins\n");
  write("-----------------------------------------\n");
  write("\n");
return 1;
}

buy(str) {
  int num;
  if(str=="sandwich") {
        num = sandwich;
        if(!random(3)) { sandwich += 1; }
  } else if(str=="noodles") {
        num = noodles;
        if(!random(3)) { noodles += 1; }
  } else if(str=="boar") {
        num = boar;
        if(!random(3)) { boar += 1; }
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


