inherit "obj/monster";
int teddybear,puppet,doll;

reset(arg) {
  teddybear -= teddybear / 14;
  puppet -= puppet / 21;
  doll -= doll / 33;
  ::reset(arg);
  if(arg) { return; }
  set_name("clown");
  set_level(44);
  set_short("A clown, selling toys");
  set_long("A smirking clown, selling beautiful puppets.\n" +
        "Type 'list' to see what he sells, and at what prices.\n");
  teddybear = 1400;
  puppet = 2100;
  doll = 3300;
}

init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}

list() {
  write("\n");
  write("The clown shows you his wares:\n");
  write("==========================================\n");
  write("A teddybear          -  "+teddybear+" coins\n");
  write("A puppet             -    "+puppet+" coins\n");
  write("An african doll      -      "+doll+" coins\n");
  write("==========================================\n");
  write("\n");
return 1;
}

buy(str) {
  int num;
  if(str=="teddybear") {
        num = teddybear;
        if(!random(3)) { teddybear += 1; }
  } else if(str=="noodles") {
        num = puppet;
        if(!random(3)) { puppet += 1; }
  } else if(str=="boar") {
        num = doll;
        if(!random(3)) { doll += 1; }
  }
  if(!num) {
write("The clown skreeches: "+str+" is not sold here.\n");
    return 1;
  }
  if(this_player()->query_money() < num) {
    write("The clown says: You will have to pay, remember?\n");
    return 1;
  }
  this_player()->add_money(-num);
  move_object(clone_object("/wizards/nalle/area/"+str), this_player());
  write("The clown tosses you a "+str+" for "+num+" coins.\n");
  say(this_player()->query_name()+" buys a toy.\n", this_player());
  return 1;
}





