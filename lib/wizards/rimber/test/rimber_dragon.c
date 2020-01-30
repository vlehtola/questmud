inherit "obj/monster";
int strena, dexi, intti, hiput, spt;
int fol, a;
string dir, tgt, master;
string str, who, i, tmp;
object ob;


string masteri() {
 master = "/wizards/rimber/test/room2.c"->master();
 say("Dragon booms: 'You called Master "+master+"?\n");
 reset();
 return master;
}
get_short(string i) { return master; }

reset(arg) {
 ::reset(arg);
 a = 0;
 fol = 0;
 strena = 400;
 dexi = 230;
 intti = 300;
 hiput = 12000;
 spt = 3000;
 if(arg) return;
 set_level(60);
 set_exp(1);
 set_str(strena);
 set_dex(dexi);
 set_int(intti);
 set_max_hp(hiput);
 set_max_sp(spt);
 set_name("dragon");
 set_short(get_short(i)+"'s red pet dragon");
 set_long("This is "+master+"'s pet dragon. Master's usually command these beasts simply\nsaying what the beast must to do.\nWord 'help' will give you more instructions.\n");
 set_skill("attack", 100);
 set_skill("bare hands", 100);
 set_skill("critical", 100);
 set_skill("enhance criticals", 100);
 set_skill("punch", 100);
 set_skill("dodge", 60);
 set_skill("find weakness", 100);
 set_skill("inner strength", 100);
 set_skill("stun", 100);
 set_skill("foresee attack", 50);
 set_mage(1);
 set_extra(1);
}

extra() {
 if(random(101) < 78) { return; }
 if(random(51) < 20) {
 say("Dragon inhales really deeply and releases a MASSIVE burst of fire over "+this_object()->query_attack()->query_name()+".\n");
 this_object()->query_attack()->hit_with_spell(300, "fire");
 }
 else {
 say("Dragon inhales deeply and exhales a red fire burst over "+this_object()->query_attack()->query_name()+".\n");
 this_object()->query_attack()->hit_with_spell(200, "fire");
 }
}
catch_tell(str) {
 string what;
 object obb, ob;
 if(sscanf(str, "%s says '%s'", who, what) == 2) {
 if(who != master) return;
  if(sscanf(what, "attack %s", tgt) == 1) {
  if(tgt == master || lower_case(tgt) == master) {
   write("That is not possible.\n");
   return;
  }
   tgt = present(lower_case(tgt), environment(this_object()));
   a = 4;
   if(!tgt) a = 7;
  }
  if(sscanf(what, "eat %s", tgt) == 1) {
   if(tgt != "corpse") {
    say("Dragon booms: 'What you want me to eat Master?'\n");
     return;
    }
  ob = present("corpse", environment(this_object()));
  if(!ob) return;
  a = 6;
  destruct(ob);
  }
 if(sscanf(what, "goto %s", tmp) == 1) {
  a = 8;
 }
 switch(what) {
  case "follow" : fol = 1;
   a = 1;
   break;
  case "help" : a = 66;
   break;
  case "stay" : fol = 0;
   a = 5;
   break;
  case "dismiss" : a = 3;
   break;
 }
 call_out("komento", 0);
 }
 if(sscanf(str, "%s leaves %s.", who, dir) == 2) {
 obb = find_player(lower_case(who));
 if(!obb) return;
 if(fol == 0) return;
 if(who != master) return;
 init_command(dir);
 }
}

status komento() {
 switch(a) {
  case 8 :
   switch(tmp) {
    case "cs" : say("Dragon booms: 'Ok. I will go to the cs.'\n");
    say("Dragon disappears.\n");
     move_object(this_object(), "/world/city/cs");
     break;
    case "home" : say("Dragon booms: 'Ok. I will go home.'\n");
     say("Dragon disappears.\n");
     move_object(this_object(), "/wizards/rimber/workroom.c");
     break;
    default : say("Dragon booms: 'Where you want me to go Master?'\n");
     break;
   }
  case 5 : say("Dragon booms: 'OK. I will stay here Master.'\n");
   break;
  case 1 : write("Dragon booms: 'Ok. I will follow you Master.'\n");
   break;
  case 3 : say("Dragon booms: 'Goodbye Master.'\n");
   say("Dragon flies away.\n");
   destruct(this_object());
   break;
  case 4 : say("Dragon booms: 'As you wish Master.'\n");
    attack_object(tgt);
    tgt = "notarget";
    a = 0;
   break;
  case 6 : say("Dragon eats the corpse.\n");
   break;
 case 7 : say("Dragon booms: 'Who I have to kill Master?'\n");
  break;
  case 66 : write("Dragon's commands:\n\n 'follow' makes dragon to follow you.\n 'stay' makes it stop following.\n 'eat corpse' Dragon eats corpse.\n 'attack <target>' Makes dragon to attack given target.\n 'dismiss' The dragon leaves.\n\n");
   break;
 }
 a = 0;
 return 1;
}

