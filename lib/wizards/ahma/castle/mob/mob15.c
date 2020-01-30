inherit "obj/monster";

reset(arg) {
  object helm, sword;
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+39);
  set_name("soul hunter");
  set_alt_name("demon");
  set_alias("hunter");
  set_short("Demonic soul hunter");
  set_long("This demons only meaning for its life is to collect and corrupt as many souls\n" + 
           "as possible. No matter if it's demon, human or animal soul. The legend tells,\n" + 
           "that the more souls this hunter corrupts the easier and better is its afterlife.\n" + 
           "These powerful bounty hunters are feared even among others of its kin. The tall\n" + 
           "figure is full of pride for its feared profession. The demon is wearing black\n" + 
           "clothing, decorated with silvered and golden chains. Some badges indicating the\n" + 
           "rank of this hunter are attached to left side of the jacket, in the chest's\n" + 
           "height. The demon is wandering around and observing others. It is carrying its\n" + 
           "still human-blooded sabre in its right hand at all times.\n");
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_str(query_str() + 70);
  set_al(-65);
  set_aggressive(0);
  set_resists("fire",100);
  set_skill_chance("kick", 60);
  set_skill_chance("tremendous blow", 20);
  set_skill("tremendous blow", 50);
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Soul hunter pats the handle of its steel sabre.\n";
    chat_str[1] = "Soul hunter examines you calculatingly.\n";
    chat_str[2] = "Soul hunter waits patiently for something to happen.\n";
  }
  load_chat(3, chat_str);
  
  helm = clone_object("/wizards/ahma/castle/eq/bonehelm");
  move_object(helm, this_object());
  init_command("wear helm");

  sword = clone_object("/wizards/ahma/castle/eq/sabre");
  move_object(sword, this_object());
  init_command("wield sabre");
}
