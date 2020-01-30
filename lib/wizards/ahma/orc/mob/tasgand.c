inherit "obj/monster";
object ob;
string plr;
int i = random(4);

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(90 + (4*i));
  set_name("tas'gand");
  set_alias("man");
  set_alt_name("chief");
  set_short("Tas'gand, the chief of Orcish village Nehelam");
  set_gender(1);
  set_race("orc");
  set_long("This Orc is coloured poisonous-green. Tas'gand is the temporary chief of\n" + 
           "the village Nehelam due to the mysterious death of the former chief Hen'gart.\n" + 
           "Tas'gand has said to have some relations to a dark cult living in unknown\n" + 
           "location somewhere underground, but nothing has been able to prove. Tas'gand\n" + 
           "is quite big and scary-looking Orc and with the help of his unknown back-\n" + 
           "ground he surely knows how to fight if needed.\n");
  
  if(!chat_str) {
    if(query_attack()) {
      chat_str = allocate(3);
      chat_str[0] = "Tas'gand shouts: 'Die, die, die!'\n";
      chat_str[1] = "Tas'gand's eyes burn as he delivers heavy blows.\n";
      chat_str[2] = "Tas'gand grins at you maniacally.\n";
    }
  }
  load_chat(3, chat_str);
  set_str(query_str() * 2);
  /*set_max_hp(query_hp() + 250000);*/
  set_hp(query_max_hp());
  set_resists("fire", 80 + random(21));
  move_object(clone_object("/wizards/ahma/orc/eq/stonemaul"), this_object());
  init_command("wield maul");
  
  if(i==0) {
    move_object(clone_object("/wizards/ahma/orc/eq/tasboots"), this_object());
    init_command("wear boots");
  }
  
  if(i==2) {
    move_object(clone_object("/wizards/ahma/orc/eq/tascloak"), this_object());
    init_command("wear cloak");
  }
  
  if(i==1) {
    move_object(clone_object("/wizards/ahma/orc/eq/tasbracers"), this_object());
    init_command("wear bracers");
  }
  
  if(i==3) {
    move_object(clone_object("/wizards/ahma/orc/eq/tasmail"), this_object());
    init_command("wear scale");
  }

  set_skill("critical", 90);
  set_skill("enhance criticals", 80);
  set_skill("find weakness", 85);
  set_skill("deceived attack", 90);
  set_skill("bludgeons", 100);
  set_skill("bare hands", 100);
  set_skill("punch", 100);
  set_skill("pound", 100);
  set_skill("throw weight", 80);
  set_skill("tremendous blow", 80);
  set_skill_chance("tremendous blow", 45);
  set_skill("round blow", 75);
  set_skill_chance("round blow", 29);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("weapon parry", 50);
  set_skill("tumble", 75);
  set_skill("reflect spell", 80);
  set_skill("counter spell", 90);
  set_mage();
  set_spell_chance(70, "exs zzt strm");
  set_skill("cast essence", 100);
  set_skill("cast electric", 100);
  set_skill("cast storm", 100);
  set_skill("theory of electricity", 90);
  set_skill("mana control", 90);
  set_skill("chanting", 100);
  set_log();
}

catch_tell(str) {
  if(sscanf(str, "%s arrives", plr) == 1) {
    ob = find_player(lower_case(plr));
    if(!ob) { return; }
    call_out("move_to", 1);
    return 1;
    }
}

move_to() {
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub19") { init_command("w"); return 1; }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub18") { init_command("stairs"); return 1; }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub16") { init_command("se"); return 1; }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub11") {
    init_command("stairs");
    tell_room("/wizards/ahma/orc/village/sub11", "Tas'gand slams the door close in the top of the stairs.\n");
    call_other("/wizards/ahma/orc/village/sub11", "remove_exit", "stairs"); 
    call_other("/wizards/ahma/orc/village/sub11", "closed");
    call_other("/wizards/ahma/orc/village/sub06", "closed");
    call_other("/wizards/ahma/orc/village/sub06", "remove_exit", "stairs");
    move_object(this_object(), "/wizards/ahma/orc/village/sub04");
    return 1;
  }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub04") { init_command("north"); return 1; }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub03") { init_command("nw"); return 1; }
  if(this_object()->query_current_room() == "/wizards/ahma/orc/village/sub02") {
  say("Tas'gand leaves ladders.\n");
  call_other("/wizards/ahma/orc/village/sub01", "moveda");
  call_other("/wizards/ahma/orc/village/house08", "remove_exit", "down");
  call_other("/wizards/ahma/orc/village/house08", "closed");
  call_other("/wizards/ahma/orc/village/house08", "moveda");
  call_other("/wizards/ahma/orc/village/bush01", "summonkillers");
  move_object(this_object(), "/wizards/ahma/orc/village/sub01");
  /*move_object(this_object(), "/wizards/ahma/orc/village/house08");*/
  set_aggressive(1);
  return 1;
  }
}
