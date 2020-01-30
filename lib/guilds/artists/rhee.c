#define GUILDRANK_D "/daemons/guildrank_d"
inherit "obj/monster";

reset(arg) {

object knu;
object knu1;

  string str;
  ::reset(arg);
  if(arg) return;
  set_level(70);
        set_max_hp(query_max_hp()*3);
        set_str(query_str()*2);
        set_dex(query_dex()*2);
        set_con(query_con()*2);
  set_name("rhee");
  set_alias("master");
  set_short("Rhee Ki Haa, the grand master of the martial arts");
  set_long("Rhee is a short and nimble man. He starts to be middle aged.\n"+
           "He has bright eyes and a strong chin. Dressed in a simple\n"+
           "robe, he watches after his young students.\n"+
           "He might be able to give your knuckles if you are a martial artist.\n");
  set_al_aggr(300);
        set_skill("two weapons combat", 100);
set_skill("sky strike", 100);
set_skill_chance("sky strike", 80);
set_skill("body anatomy", 80);
set_skill("claws storm", 80);
set_skill("focused sky strike", 70);
set_skill("whirlwind", 80);
  str = allocate(4);
  str[0] = "Rhee examines your body.\n";
  str[1] = "Rhee says: 'Martial artists are the real combat masters!'\n";
  str[2] = "Rhee makes some strange maneuvers.\n";
  str[3] = "Rhee says: 'Just ask if you need your knuckles and i check if you are advanced enough.'\n";
  load_chat(15,str);
  set_gender(1);
  set_log();
        knu = clone_object("/guilds/artists/wepat/gm");
        move_object(knu, this_object());
knu1 = clone_object("/guilds/artists/wepat/gm");
move_object(knu1, this_object());
init_command("wield knuckles");
init_command("wield knuckles 2");
}

ask_question(str) {
       string rank, guild;
        object knuckles;
        object knuckles2;
        int score, max_score, k_lvl;
        guild = "martial artist";
        if(str == "knuckles") {
          if( GUILDRANK_D->is_member_of_guild(this_player(), guild) ) {
                score = GUILDRANK_D->count_rank_score(this_player(), guild, 0, 0);
                max_score = GUILDRANK_D->define_max_score(guild);
                rank = GUILDRANK_D->get_rank_status(guild, score);

                if(this_player()->query_tester() || this_player()->query_wiz()) {
                  write("Rank: "+rank+".\n");
                }

                if(score > 0) {
 
                //k_lvl changed by Rag 16.10.2005
                // yet by C. min rank is 0, yellow knuckles is 3. so add 2
                k_lvl = GUILDRANK_D->get_rank_level(guild,score) + 2;
                knuckles = clone_object("/guilds/artists/knuckles_artist");
                knuckles2 = clone_object("/guilds/artists/knuckles_artist");
                knuckles->set_knuckle_level(k_lvl);
                knuckles2->set_knuckle_level(k_lvl);
/*
                if(rank == "a takitu") {
                } else if(rank == "a ryotaka") {
                } else if(rank == "a zasenro") {
                } else if(rank == "a wahringust") {
                } else if(rank == "a sabumnim") {
                } else if(rank == "a sarinku") {
                } else if(rank == "a saizenso") {
                } else if(rank == "a Master of mind and body") {
 
*/
                 } else {
                        write("You are not allowed to receive the knuckles");
                        return 1;
                }

                if(present("nyrkkirauta",this_player())) {
                        write("Rhee says: 'But you already have knuckles.\n");
                        return 1;
                }

                if(knuckles) {
                        write("Rhee smiles happily and gives your knuckles.\n");
                        move_object(knuckles,this_player());
                        move_object(knuckles2,this_player());
                        return 1;

                }
          }
         }
}
