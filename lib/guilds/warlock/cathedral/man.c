inherit "obj/monster";
#define WARLOCK_D "/daemons/warlock_d"
string *corpses;
int corpse_quest;
mapping collectors;
string chat_str;
reset(arg) {

     corpses = ({ "Rabbit", "Man", "Bear", "Fisherman", "Armourer", "Wolf", "Orc", "Cow", "Horse", "Mouse", "Dog", "Rooster", "Pig", "Chicken", "Sheep", "Deer", "Animal", "Lizardman", "Demon", "Ninja", "Imp", "Husky", "Wolverine", "Mink", "Alligator", "Bum", "Child", "Eagle", "Fox", "Frog", "Hitman", "Hunter", "Moose", "Seashell", "Lynx", "Snake", "Ranger", "Cyclop", "Spider", "Paladin", "Priest", "Angel", "Snail", "Pudding", "Salesman", "Pilgrim", "Monk", "Boy", "Guard", "Tellu", "Gnome", "Aristocrat", "Kalle", "Lalli", "Pony", "Crab", "Ogre","Servant", "Elemental", "Golem", "Cook", "Summoner", })[random(63)];
     corpse_quest=0;
	chat_str = allocate(2);
	chat_str[0] = "The man says: 'I need help with corpses\n";
	chat_str[1] = "The man says: 'I Might have a couple of tasks for you'\n";
     ::reset(arg);
     if(arg) {return; }
     collectors = ([ ]);
     set_name("man");
     set_level(50+random(10));
     set_gender(1);
     set_random_pick(0);
     set_al(-50);
     set_al_aggr(200);
     set_alias("robed");
     set_move_at_reset();
     set_short("A man clad in black robes is wandering here");
     set_long(
	 "The skeletal body of this man is covered with black robes. The man looks like a undead of some sort because when he moves you can see a glimse of his bones. He looks quite tall and dangerous. He is wearing a somekind of crown with lots of smaller rubys and the center of the crown is eye, probably a dragon eye. Its is sayed that this man knows all the things conserning chaos and demons.\nHe is a lich.\n");
	set_undead();
	set_str(query_str()+300);
	set_max_hp(query_hp()+10000);
	set_hp(query_max_hp());
    load_chat(5, chat_str);
	}
query_collect(str) { return collectors[str]; }

ask_question(str) {
if(str == "chamber" || str == "chambers") {
say("The man says: 'The ancient scrolls indicate that the secret chamber of warlocks is behind of something. I don't know precisely where it is but once a young warlock said that she founded it eastern part of this cathedral but she died short after when she founded that guild and tried to summon a special demon.'\n");
return 1;
}
if(str == "corpses" || str == "corpse") {
say("The man says: 'Yes i need some one to collect corpses for me'\n");
do_corpse_task();
return 1;
}
if(str == "summon" || str == "summoning") {
say("The man says: 'It is know that the cathedral holds a summoning chamber where even lousiest warlocks can accomplish their summoning attempts.'\n");
return 1;
}
if(str == "demon" || str == "demons") {
say("The man says: 'Ah the chaos demons. They are the most chaotic creatures ever stepped on this realm but same time they are the most excisting things to work with. You can check how powerfull demons you can summon in this realm at the main guild room.'\n");
return 1;
}
if(str == "warlock" || str == "warlocks") {
say("The man says: 'Yes i am the warlock, king of all chaotic creatures and souls. You can also ask rules from me'\n");
return 1;
}
if(str == "task" || str == "tasks") {
say("The man says: 'Yes i have couple of tasks.'\n");
do_tasks();
return 1;
}
if(str == "rules") {
say("The man shows you a book labeled ' The rules of Warlock guild'\n");
say("\n#1 Do not cheat! if the dark gods find out that you are cheating then they might lower your demon experience and souls to zero! You might be even kicked out of warlocks without the posibility to ever return to this guild");
say("\n#2 If you one day find out that your demon aren't taking any shape from damage, dismiss it instantly and mudmail siki what happened to the demon and describe the problem as precisely what you know about how it occured and what might caused it. Ps: This will certainly lower your demonxp|souls to zero and kick you out of the guild");
say("\n#3 You might find features|bugs from this guild, mudmail them to siki without exploiting them.\n");
return 1;
}
say("The man says: 'I don't know anything about that'\n");
return 1;
}
/* Tasks are
Rescue the warlock from temple of light

*/
do_corpse_task() {
if(corpse_quest==1) {
write("The man says: 'I don't need a corpses just now. Wait a couple of minutes and then i might need.\n");
return 1;
}
write("The man says: 'Currently i am seeking a 'Corpse of "+corpses+"'. I am willing to reward you if you bring me that corpse.\n");
return 1;
}

do_tasks() {
if(!this_player()->query_quests("Find the secret chamber of warlocks")) {
write("The man says: 'I have heard that inside this cathedral is a secret chamber of warlocks. I need you to find where it is.\n");
return 1;
}

write("The man says: 'You can also ask me about 'corpses'.\n");
return 1;
}

catch_tell(str) {
string tmp1, tmp2;
object ob;
object *obs;
int i;
if(sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
ob = present("corpse", this_object());
if(ob) {
do_corpse(ob);
return 1;
}
obs = all_inventory(this_object());
for(i=0;i<sizeof(obs);i++) {
move_object(obs[i], environment(this_object()));
}
write("Man says: 'I don't need that.'\n");
say("Man drops something.\n");
return 1;
}
}

do_corpse(object ob) {
string str;
int souls;
int xp;
if(corpse_quest == 1) {
move_object(ob, environment(this_object()));
say("Man drops corpse.\n");
say("The man says: 'I already have a corpse of that kind.'\n");
say("The man says: 'Try again i while when i need a new one.'\n");
return 1;
}
if(collectors[this_player()->query_real_name()] > 20) {
write("The man says: You have collected enough corpses for me. Maybe you should let some other person also collected them?\n");
destruct(ob);
return 1;
}

str = ob->short();
if(sscanf(str, "Corpse of %s", str) == 1) {
if(str == corpses) {
say("The man says: 'Good just that kind of corpse that i need.'\n");
souls = random(ob->query_level()*100)+100;
xp = random(ob->query_level()*10000)+10000;
WARLOCK_D->add_souls(this_player()->query_real_name(), souls);
WARLOCK_D->add_demon_xp(this_player()->query_real_name(), xp);
this_player()->add_alignment(-5);
write("Dark gods rewards you "+souls+" souls and "+xp+" demon experience.\n");
corpse_quest=1;
chat_str[0] = "The man searches around like looking for something.\n";
collectors[this_player()->query_real_name()]+=1;
return 1;
}
say("The man says: 'I don't need that corpse.'\n");
move_object(ob, environment(this_object()));
return 1;
}

}
