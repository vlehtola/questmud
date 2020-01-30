#define GUILDRANK_D "/daemons/guildrank_d"
inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }

	set_name("monsteri");

        set_level(1);

        set_al(0);
        set_al_aggr(400);
        set_aggressive(0);

        set_short("Hiano monsteri");
	set_long("T�lt� monsterilta kannattaa kysy� knuckleseista.\n");
}

ask_question(str) {
	string rank, guild;
	object knuckles;
	int score;
	guild = "martial artist";
	if(str == "knuckles") {
	  if( GUILDRANK_D->is_member_of_guild(this_player(), guild) ) {

		score = GUILDRANK_D->count_rank_score(this_player(), guild, 0, 0);
		GUILDRANK_D->define_max_score(guild);
		rank = GUILDRANK_D->get_rank_status(guild, score);

		if(rank == "a beginner of arts of war") {
				knuckles = clone_object("/wizards/moonstar/artists/wepat/white");
		} else if(rank ==  "a martial artist") {
				knuckles = clone_object("/wizards/moonstar/artists/wepat/yellow");
		} else {
			write("You are not allowed to receive the knuckles");
			return 1;
		}

		if(knuckles) {
			write("Jeejee, sait knucklesit!\n");
			move_object(knuckles,this_player());
			return 1;
		}
	  }
	}
}
