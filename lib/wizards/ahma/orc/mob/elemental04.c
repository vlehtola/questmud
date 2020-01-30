inherit "obj/monster";
int cloned, i = random(3);

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level((i*3) + 80);
  set_name("kleod");
  set_alt_name("leader");
  set_alias("elemental");
  set_short("Kleod, an ancient leader of earth elementals");
  set_long("A small-sized earth elemental is standing in the tunnel. The elemental is\n" + 
           "about five feet tall and does not even seem to possess noticeable-sized\n" + 
           "muscles. Though, unlike other elementals, this one seems to be wearing\n" + 
           "armour and weapons. It is said that Kleod was the one who was responsible\n" + 
           "for numerous earth elemental riots which eventually led to the great Earth\n" + 
           "Elemental War in the Plane of Elementals about eight hundred years ago.\n");
  if(!chat_str) {
    if(query_attack()) {
      chat_str = allocate(3);
      chat_str[0] = "Kleod curses at you.\n";
      chat_str[1] = "Kleod stony face twists into a freaky grin as it delivers heavy blows.\n";
      chat_str[2] = "Kleod laughs hysterically at you.\n";
    }
  }
  load_chat(3, chat_str);
  
  set_resists("electric", 80 + random(21));
  set_max_hp(query_hp() + 230000);
  set_hp(query_max_hp());
  set_aggressive(1);
  set_special(16);

  move_object(clone_object("/wizards/ahma/orc/eq/earthplate"), this_object());
  init_command("wear plate");
  
// move_object(clone_object("/wizards/ahma/orc/eq/stonehammer"), this_object()); //
//  init_command("wield hammer"); //
  
// move_object(clone_object("/wizards/ahma/orc/eq/stonehammer"), this_object()); //
//  init_command("wield hammer"); //
  
  if(i==1) {
    move_object(clone_object("/wizards/ahma/orc/eq/earthring"), this_object());
    init_command("wear ring");
  }
  
  if(i==2) {
    move_object(clone_object("/wizards/ahma/orc/eq/earthhelm"), this_object());
    init_command("wear helm");
  }
  set_str(query_str() + 300);
  set_skill("two weapons combat", 100);
  set_skill("doublehit", 90);
  set_skill("weapon parry", 100);
  set_skill("parry", 90);
  set_skill("tumble", 40);
  set_skill("reflect spell", 60);
  set_skill("counter spell", 70);
  set_skill("tremendous blow", 70);
  set_skill_chance("tremendous blow", 40);
  set_skill("round blow", 70);
  set_skill_chance("round blow", 23);
  set_mage();
  set_spell_chance(60, "exs fla strm");
  set_spell_chance(30, "exs brr strm");
  set_skill("cast essence", 90);
  set_skill("cast fire", 100);
  set_skill("cast ice", 100);
  set_skill("cast storm", 85);
  set_skill("mana control", 79);
  set_skill("chanting", 80);
  set_skill("knowledge of heat", 80);
  set_skill("lore of cold", 80);
  set_skill("critical", 80);
  set_skill("enhance criticals", 60);
  set_skill("find weakness", 60);
  set_resists("electric", 100);
  set_al(-120);
}

special_move() {
  if(cloned < 5) {
    say("The blue wall flashes and a hostile earth elemental minion enters the room through it.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/elemental05"), environment(this_object()));
    cloned++;
  }
}

reducecloned() {
  cloned--;
}
