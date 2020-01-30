inherit "obj/monster";
int tankard;
int map;
object apron,sword;
reset(arg) {
        tankard -= tankard / 10;
        map -= map / 10;
        ::reset(arg);
        if(arg) {return; }
        set_name("lasca");
        set_level(55+random(3));
        set_gender(1);
        set_race("human");
        set_al(-10);
        set_special(70);
        set_short("Lasca the owner of this inn");
        set_long("He is the owner of this inn. He looks like quite old man with a hard look\n"+
                 "on his face. He is wearing typical bartender clothes, a leather apron\n"+
                 "and trousers. He is cleaning the trash from the tables, and surely\n"+
                 "seems like a person who knows plenty of things. He is also selling some items.\n");
        set_skill("strike", 100);
        set_skill("tremendous blow", 100);
        set_skill_chance("strike", 60);
        set_log();
        set_max_hp(query_hp()+59999);
                set_hp(query_max_hp());
        tankard = 2000;
        map = 1000;
        apron = clone_object("/wizards/neophyte/city/obj/apron");
        move_object(apron, this_object());
        sword = clone_object("/wizards/neophyte/city/eq/lsword");
        move_object(sword, this_object());
        init_command("wear coat");
        init_command("wield claymore");

}

init() {
  ::init();
  add_action("list", "list");
  add_action("buy", "buy");
}

list() {
  write("Lasca shows you the current menu:\n");
  write("Tankard of beer    "+tankard+" bronze coins\n");
  write("Map of city        "+map+" bronze coins\n");
  write("\n");
  return 1;
}

buy(str) {
  int num;
  if(str=="tankard") {
        num = tankard;
        if(!random(5)) { tankard += 1; }
  }
  if(str=="map") {
          num = map;
          if(!random(5)) { map += 1; }
  }
  if(!num) {
    write("The lasca says: There are no "+str+" for sale currently.\n");
    return 1;
  }
  if(this_player()->query_money(3) < num) {
    write("The lasca says: Sorry, but you don't have enough bronze coins.\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  move_object(clone_object("/wizards/neophyte/city/obj/"+str), this_player());
  write("You buy one "+str+" with "+num+" coins.\n");
  say(this_player()->query_name()+" buys something.\n", this_player());
  return 1;
}

ask_question(str) {
        if(str == "orb") {
                say("Lasca says: 'Yes the orb of the everlasting sun.'\n");
                say("Lasca says: 'I have heard you can somehow activate the orb.\n");
                return 1;
        }
        if(str == "graveyard") {
                        say("Lasca says: 'The graveyard is guarded by the keeper.'\n");
                        return 1;
                }
                if(str == "keeper") {
                        say("Lasca says: 'The keeper opens the door only a certain time of day and you have to know the right thing to get inside the graveyard.'\n");
                        return 1;
                }
                if(str == "crystal") {
                        say("Lasca says: 'I have heard that the crystal have something to do with ghosts.\n");
                        say("Lasca says: 'But i don't know exacly what.'\n");
                        return 1;
                }
                if(str == "lowie") {
                        say("Lasca says: 'The lowie family are the runners of weapon and armour shops.'\n");
                        say("Lasca says: 'The Loxie can make beautiful armours from hides.'\n");
                        return 1;
                }
                if(str == "bone door") {
                        say("Lasca says: 'The door open when some one knocks on it.\n");
                        return 1;
                }
                if(str == "ghost") {
                        say("Lasca says: 'The ghost can be killed with crystal, but how that i dont know.'\n");
                        return 1;
                }
                if(str == "inn") {
                        say("Lasca says: 'We have a couple of customers that come to sleep here almost every night.\n");
                        return 1;
                }
                if(str == "thief") {
                        say("Lasca says: 'Beware of that thief, he can sometimes be quite a bad opponent in a fight.'\n");
                        return 1;
                }
                if(str == "cereon") {
                        say("Lasca says: 'That Cereon have found something from the sea, when his family was killed.\n");
                        return 1;
                }
                if(str == "wolfrider") {
                        say("Lasca says: 'The wolfriders are pain in the ass. They come here at nights and rob people.'\n");
                        return 1;
                }
                if(str == "drake") {
                        say("Lasca says: 'Ah the keeper of lighthouse, he can sometimes drink a whole tankard of beer.\n");
                        return 1;
                }
                if(str == "lighthouse") {
                        say("Lasca says: 'You should not go inside the lighthouse, i have heard that there lives an ancient ghost.\n");
                        return 1;
                }
                if(str == "renisa") {
                        say("Lasca says: 'This is quite powerfull sword and helps you to fight with ogres.'\n");
                        return 1;
                }
                if(str == "kyriec") {
                        say("Lasca says: 'She is one of the elders at witch guild.'\n");
                        return 1;
                }
                say("Lasca says: 'I don't know anything about that.'\n");
                return 1;
        }
