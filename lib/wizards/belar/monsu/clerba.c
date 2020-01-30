inherit "obj/monster";
int hpbless,spbless,rmscar;
reset(arg) {
 hpbless -= hpbless / 3;
 spbless -= spbless / 3;
 rmscar -= rmscar / 1;
    ::reset(arg);
    if(arg) { return; }
set_name("dwarf");
set_level(65);
set_dex(1000);
set_int(5000);
set_wis(5000);
set_skill("channel", 100);
set_skill("chanting", 100);
set_skill("cast divine", 100);
set_skill("cast bless", 100);
set_skill("mana control", 100);
set_skill("cast minor", 100);
set_skill("cast lesser", 100);
set_skill("cast mastery of medicine", 100);
set_skill("cast heal", 100);
set_skill("cast cure", 100);
set_skill("cast holy alteration", 100);
set_gender(1);
set_alias("dwarf");
   set_short("A Dwarf is selling clerical services");
   set_long("Very elegantly dressed dwarf has a long white cape.\n"+
             "Dwarf has some sort of list in his hand.You can sense his wisdom\n"+
             "Maybe you should type <list> to see what he offers.\n");
    set_al_aggr(100);
    set_race("dwarf");
  hpbless = 3;
  spbless = 3;
  rmscar = 1;
}

init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}

list() {
  write("\n");
  write("Cleric smiles and shows you the list:\n");
  write("-----------------------------------------\n");
  write("A hitpoint Bless (hpbless)    - "+hpbless+" coins\n");
  write("A spellpoint Bless (spbless)  - "+spbless+" coins\n");
  write("A remove scar  (rmscar)       - "+rmscar+" coins\n");
  write("-----------------------------------------\n");
  write("\n");
return 1;
}

buy(str) {
  int num;
  if(str=="hpbless") {
        num = hpbless;
        if(!random(3)) { hpbless += 1; }
  } else if(str=="spbless") {
        num = spbless;
        if(!random(3)) { spbless += 1; }
  } else if(str=="rmscar") {
        num = rmscar;
        if(!random(3)) { rmscar += 1; }
 }
  if(!num) {
write("Cleric grunts: We don't know how to cast "+str+" in here.\n");
    return 1;
  }
  if(this_player()->query_money() < num) {
    write("Cleric booms: I only accept bronze.\n");
    return 1;
  }
  this_player()->add_money(-num);
  move_object(clone_object("/wizards/nalle/area/"+str), this_player());
  write("Cleric starts to cast "+str+"  at you since you payed "+num+" coins.\n");
  say(this_player()->query_name()+" Buys an enchantment.\n", this_player());
  return 1;
}
