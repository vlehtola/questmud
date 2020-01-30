/*
New mastery system -- Rag
Coded to prevent abuse of old mastery system
and to add some difficulty to gaining masteries
Started coding 17.11.2003
Mastery_d is basicly ready, 22.11.2003
Now I have to code all the skills and spells...

After 10 hours of checking through skills and spells,
the masteries are ready, --Rag 23.11.2003

I made it harder to get masteries --Rag 26.11.2003

Added a small bonus for eq-monsters, --Rag 30.11.2003

Masteries are now harder to get but reinc takes only 10% of them --Rag 2.6.2004

To gain magemasteries, your offensive boost must be atleast sp_max * 5% or 120,
which ever is lower -- Rag 7.10.2004

And there are the masteries:
Fighter skills:         Offensive maneuvers     done
Mage:                   Offensive spellcasting  done
Mage/abju elements:     Dangerous <element>     done
Abju prots:             Knowledge of shielding  done
Abju vulns:             Knowledge of weaknesses done
Healing:                Holy faith              done
Psi for bigger mobs:    Expanded mind           done
Psi for dam/spcost:     Power of the mind       done
Necro:                  Mastery of dark arts    done


Artists have a slightly different mastery system
You have to check the mastery ARTISTS times
to increase the mastery, no random stuff
*/
#define SAVEFILE "/data/artists"
#define ARTISTS(ob) 400*3/(ob->query_rebirth()+3)

//Mappings for different artist-masteries
mapping body;
mapping mind;

void reset(status arg) {
        if(arg) return;
        //Load martial artist masteries
        if(!restore_object(SAVEFILE)) {
                body = ([]);
                mind = ([]);
                save_object(SAVEFILE);
        }
}

//Returns the value of mastery and checks if the object
//gains more masteries
//Arguments: name of mastery, object with mastery, target

int mastery(string mastery, object ob, object target) {
        int mastery_level, ob_level, target_level, bonus, m_check;
        string calling_file, second_caller, element, tmp, tname;

        //NPCs don't have masteries
        if(ob->query_npc()) return 0;
        //Mastery of object must be given
        if(!mastery || !ob) return 0;

        //Target must be alive
        if( target && !living(target) ) return mastery_level;

        mastery_level = ob->query_mastery()[mastery];
        ob_level = ob->query_level();

        //No need to check any futher
        if (mastery_level == 100) return mastery_level;

        //You would get crazy results from the wizards' levels
        if (target && target->query_wiz()) return mastery_level;

        target_level = 0;
        tname = "";
        if(target) {
                target_level = target->query_level();
                tname = target->query_name();
        } else {
          target_level = 0;
          tname = "";
        }

        calling_file = file_name(previous_object());

        if(previous_object(1)) {
                second_caller = file_name(previous_object(1));
        } else {
          second_caller = "";
        }
        
//Melee skills
        if(mastery == "Offensive maneuvers") {

                if(!target || !target->query_npc() ) return mastery_level;
                if(target_level < ob_level / 10) return mastery_level;

                bonus = 0;
                if(calling_file == "/guilds/skills/strike") bonus = 20;
                if(calling_file == "/guilds/skills/tremendous_blow") bonus = 40;
                //This because you have a chance to do treme with strike
                if(second_caller == "/guilds/skills/strike") bonus = 30;
                if(calling_file == "/guilds/skills/battlecry") bonus = 30;
                if(sscanf(calling_file,"/guilds/skill_obj/round_blow_object#%d",tmp)) bonus = 30;
                
                m_check = mastery_level*2+180-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
        }

//General mage mastery
        if(mastery == "Offensive spellcasting") {

                if(!target || !target->query_npc() ) return mastery_level;
                if(target_level < ob_level / 20) return mastery_level;
                
                int sp_limit;
                if ( ob->query_max_sp() * 5 / 100 > 120 ) {
                  sp_limit = 120;
                } else {
                  sp_limit = ob->query_max_sp() * 5 / 100;
                }
                
                if ( ob->query_sp_boost(1) < sp_limit ) { return mastery_level; }

                bonus = 0;
                if(calling_file == "/guilds/obj/area_resolve") bonus = 30;
                
                m_check = mastery_level*2+100-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
                m_check += m_check / 3;
        }

//Elemental
        if(sscanf(mastery,"Dangerous %s",element)) {

                if(!target) return mastery_level;
                if(!target->query_npc() && calling_file != "/guilds/spell_obj/protection") return mastery_level;
                if(target->query_npc() && calling_file == "/guilds/spell_obj/protection") return mastery_level;
                if(target_level < ob_level / 20) return mastery_level;

                int sp_limit;
                if ( ob->query_max_sp() * 5 / 100 > 120 ) {
                  sp_limit = 120;
                } else {
                  sp_limit = ob->query_max_sp() * 5 / 100;
                }
                
                if ( ob->query_sp_boost(1) < sp_limit && (calling_file == "/guilds/spell_obj/offensive_resolve"
                     || calling_file == "/guilds/spell_obj/area_resolve" ) ) {
                      return mastery_level;
                }

                bonus = 0;
                if(calling_file == "/guilds/obj/area_resolve") bonus = 20;
                if(calling_file == "/guilds/spell_obj/protection") bonus = 70;
                if(calling_file == "/guilds/spell_obj/vulnerability") bonus = 70;
                
                m_check = mastery_level*2+70-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
                m_check += m_check / 5;
        }

//Healing
        if(mastery == "Holy faith") {

                if(!target) return mastery_level;
                if ( !sscanf(calling_file,"/guilds/spells/channel/_chl_xfr_%s",tmp)
                     && target->query_npc() ) {
                        return mastery_level;
                }
                if(!target->query_npc() && query_idle(target) > 60) {
                        return mastery_level;
                } else if(target_level < ob_level / 20) {
                        return mastery_level;
                }

                bonus = 0;
                if(sscanf(calling_file,"/guilds/spells/channel/_chl_%s_les",tmp)) bonus = 10;
                if(sscanf(calling_file,"/guilds/spells/channel/_chl_%s_mar",tmp)) bonus = 20;
                if(sscanf(second_caller,"/guilds/spells/channel/_chl_%s_les",tmp)) bonus = 10;
                if(sscanf(second_caller,"/guilds/spells/channel/_chl_%s_mar",tmp)) bonus = 20;
                if(sscanf(second_caller,"/guilds/spells/channel/_chl_kfq_%s",tmp)) bonus = -50;
                                
                m_check = mastery_level*2+130-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
                
                if(target == ob) m_check *= 3;
        }

//Protection
        if(mastery == "Knowledge of shielding") {

                if(!target || target->query_npc() ) return mastery_level;
                if( !target->query_npc() && query_idle(target) > 60 ) {
                        return mastery_level;
                }

                bonus = 0;
                if(sscanf(calling_file,"/guilds/spells/abjuration/_kyo_%s_dio",tmp)) bonus = 20;
                if(sscanf(calling_file,"/guilds/spells/abjuration/_kyo_%s_yed",tmp)) bonus = 20;
                
                m_check = mastery_level*2+80-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
                
                if(target == ob) m_check *= 3;
        }

//Vulns
        if(mastery == "Knowledge of weaknesses") {

                if(!target || !target->query_npc()) return mastery_level;
                if(target_level < ob_level / 20) return mastery_level;

                m_check = mastery_level+30-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
        }

//Psi
        if(mastery == "Expanded mind") {

                if(target && !target->query_npc()) return mastery_level;
                if(target && target_level < ob_level / 20) return mastery_level;

                bonus = 0;
                if(calling_file == "/guilds/skills/mental_expansion") bonus = 30;
                if(calling_file == "/guilds/psi/specials/psicombat") bonus = -270-mastery_level;

                m_check = mastery_level*2+135-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
        }

//Psi
        if(mastery == "Power of the mind") {

                if(calling_file == "/guilds/psi/specials/psicombat") bonus = -290-mastery_level;

                m_check = mastery_level*2+120-bonus-target_level/5+ob_level/20;
                if(!m_check) m_check = 1;
        }

//Necro 
        if(mastery == "Mastery of dark arts") {

                bonus = 0;
                if(sscanf(calling_file,"/guilds/spells/necromancy/_doo_%s_moo",tmp)) bonus = 10;
                if(sscanf(calling_file,"/guilds/spells/necromancy/_doo_%s_muu",tmp)) bonus = 20;

                m_check = mastery_level*2+45-bonus;
                if(!m_check) m_check = 1;
        }

//Martial arts masteries
        if(mastery == "Mastery of body focusing") {

                if(!target || !target->query_npc()) return mastery_level;
                if(target_level < ob_level / 20) return mastery_level;

                if(body[ob->query_name()]) {
                        body[ob->query_name()]++;
                } else {
                        body += ([ (string) ob->query_name() : 1 ]);
                }
                if(body[ob->query_name()] > ARTISTS(ob)) {
                        mastery_level++;
                        ob->set_mastery(mastery,mastery_level);
                        body[ob->query_name()] = 1;
                }
                save_object(SAVEFILE);
                return mastery_level;
        }                       

        if(mastery == "Mastery of mind focusing") {

                if(!target) return mastery_level;
                if(query_idle(target) > 60) return mastery_level;

                if(mind[ob->query_name()]) {
                        mind[ob->query_name()]++;
                } else {
                        mind += ([ (string) ob->query_name() : 1 ]);
                }
                if(mind[ob->query_name()] > ARTISTS(ob)/2) {
                        mastery_level++;
                        ob->set_mastery(mastery,mastery_level);
                        mind[ob->query_name()] = 1;
                }
                save_object(SAVEFILE);
                return mastery_level;
        }

//If the mastery doesn't exist
        if(!m_check) return 0;

        if(m_check < 0) m_check = 0;

//Bonus for eq mobs
        if(target && target->query_kill_log()) {
                m_check = m_check / 5;
        }

//Bonus for rebirthers
        if(ob->query_rebirth()) {
                m_check = m_check * 5 / (ob->query_rebirth() + 5);
        }

        if(ob->query_tester() || ob->query_wiz()) tell_object(ob,m_check+"\n");

        if(!random(m_check)) {
                mastery_level++;
                ob->set_mastery(mastery,mastery_level);
        log_file("MASTERY", ctime(time())+" "+ob->query_name()+" M: "+mastery+" %: "+mastery_level+
        " L: "+ob_level+" "+target_level+" C: "+m_check+"\n",1);
        }
        
        return mastery_level;
}

//Get masteries without gaining them
int query_mastery(string mastery, object ob) {
        if(!mastery || !ob) return 0;
        if(ob->query_npc()) return 0;

        return ob->query_mastery()[mastery];
}
