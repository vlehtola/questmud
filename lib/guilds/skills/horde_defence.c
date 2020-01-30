//Horde takes necromancer's hits -- Rag 3.2.2004

// skill to be removed from the game. Oct 2005 Celtron

#define MASTERY_D "/daemons/mastery_d"

int ep_cost() { return 5; }

get_time() { return 5; }

resolve_skill(str) {
	int time;
	object ob;

	write("You command your horde to defend you in battle.\n");
	say(this_player()->query_name()+" commands the horde.\n");

	time = this_player()->query_int();
	time += this_player()->query_skills("horde defence")*2;

	time += MASTERY_D->mastery("Mastery of dark arts",this_player());

	//int ~150 + skill 200 + mastery 100 = 350 seconds

	ob = clone_object("/guilds/skill_obj/horde_def_ob");

	ob->start(this_player(),time);
	return 1;
}

fail_skill() {
	write("You fail to command your horde.\n");
	say(this_player()->query_name()+" fails to command the horde.\n");
	return 1;
}
