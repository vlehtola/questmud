
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
        int score;
        guild = "martial artist";
        if(str == "knuckles") {
          if( GUILDRANK_D->is_member_of_guild(this_player(), guild) ) {
                score = GUILDRANK_D->count_rank_score(this_player(), guild, 0, 0);
                GUILDRANK_D->define_max_score(guild);
                rank = GUILDRANK_D->get_rank_status(guild, score);
                if(rank == "a beginner of arts of war") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/white");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/white");
                } else if(rank ==  "a martial artist") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/yellow");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/yellow");
                } else if(rank ==  "a body and mind focuser") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/green");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/green");
                } else if(rank ==  "a veteran martial artist") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/blue");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/blue");
                } else if(rank ==  "a teacher of arts of war") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/red");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/red");
                } else if(rank ==  "a master of combat") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/black");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/black");
                } else if(rank ==  "a grand master of combat") {
                                knuckles = clone_object("/wizards/moonstar/artists/wepat/gm");
knuckles2 = clone_object("/wizards/moonstar/artists/wepat/gm");
               } else {
                        write("You are not allowed to receive the knuckles");
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


