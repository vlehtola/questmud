/* New emote system */

#include <ansi.h>
#define TPNAME this_player()->query_name()
#define MIUKUBOLD CYAN_F+"@"+OFF

status emote(string verb, string target, string adverb, string bodypart);
status remoteemote(string verb, string target, string adverb, string bodypart);
status parse(string str);
string get_adverb(string str);
string get_bodypart(string str);
string get_emote(string str, int query);
string genitalia(string str);


get() { return 1; }

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

init() {
    add_action("parse", "",1);
}

/****************************************************************/

string get_emote(string str, int query) {

// With query value 0, we check if emote exists
// It also then returns the 'at' or 'with' etc, that is needed
if (query==0) {
if(str == "ack") { return str+" at"; }
if(str == "agree") { return str+" with"; }
if(str == "ah") { return str+" at"; }
if(str == "apologize") { return str+" to"; }
if(str == "applaud") { return str+" at"; }
if(str == "argh") { return str+" at"; }
if(str == "bark") { return str+" at"; }
if(str == "beg") { return str+" at"; }
if(str == "bleed") { return str+" on"; }
if(str == "blink") { return str+" at"; }
if(str == "blush") { return str+" at"; }
if(str == "boo") { return str+" at"; }
if(str == "bore") { return str; }
if(str == "bounce") { return str+" around"; }
if(str == "bow") { return str+" at"; }
if(str == "burp") { return str+" at"; }
if(str == "cackle") { return str+" at"; }
//if(str == "caress") { return str+"e"; } joo mieti
if(str == "cheer") { return str+" at"; }
if(str == "chuckle") { return str+" at"; }
if(str == "clap") { return str+" at"; }
if(str == "click") { return str+" at"; }
if(str == "comfort") { return str; }
if(str == "confuse") { return str; }
if(str == "congratulate") { return str; }
if(str == "cough") { return str+" at"; }
if(str == "croak") { return str+" at"; }
//if(str == "cry") { return str+" at"; }
if(str == "cuddle") { return str+" up to"; }
if(str == "curse") { return str+" at"; }
if(str == "curtsey") { return str+" before"; }
if(str == "dance") { return str+" with"; }
if(str == "disagree") { return str+" with"; }
if(str == "dream") { return str+" about"; }
if(str == "drool") { return str+" at"; }
if(str == "eww") { return str+" at"; }
if(str == "eep") { return str+" at"; }
if(str == "fart") { return str+" at"; }
if(str == "fear") { return str; }
if(str == "flex") { return str+"e at"; }
if(str == "flip") { return str+" at"; }
if(str == "flirt") { return str+" with"; }
if(str == "fondle") { return str; }
if(str == "freeze") { return str; }
if(str == "frown") { return str+" at"; }
if(str == "gasp") { return str+" at"; }
if(str == "giggle") { return str+" at"; }
if(str == "gigglesnort") { return str+" at"; }
if(str == "glare") { return str+" at"; }
if(str == "glug") { return str+" at"; }
if(str == "greet") { return str; }
if(str == "grin") { return str+" at"; }
if(str == "groan") { return str+" at"; }
if(str == "grope") { return str; }
if(str == "growl") { return str+" at"; }
if(str == "grr") { return str+" at"; }
if(str == "gurgle") { return str+" at"; }
if(str == "hail") { return str; }
if(str == "hiccup") { return str+" at"; }
if(str == "hmm") { return str+" at"; }
if(str == "hmpf") { return str+" at"; }
if(str == "hmph") { return str+" at"; }
if(str == "hug") { return str+" at"; }
if(str == "hum") { return str+" at"; }
if(str == "kick") { return str; }
if(str == "kiss") { return str+"es"; }
if(str == "knee") { return str; }
if(str == "laugh") { return str+" at"; }
if(str == "lick") { return str; }
if(str == "moan") { return str+" at"; }
               }

// As query value 1, an optional default adverb for the emote
// is returned. (Only used if no adverb is specified too)
if (query==1) {
if(str == "hohhoh") { return "merrily"; }
               } 

// As query value 2, an optional default target for the emote
// is returned. (Only used if not defined, and is NOT told to)
if (query==2) {
if(str == "wonder") { return "this and that"; }
               } 

return 0;
}

/*******************************************************************/

status parse(string str) {
string *array;
string verb,target,adverb,bodypart;
int i;

// Debugging
write("'"+str+"' == str\n");
write("'"+lower_case(query_verb())+"' == query_verb()\n");

// Check that the command is an emote, else return 0
verb=get_emote(query_verb(),0);
if(!verb) return 0;

// An emote with no string->call it. fe. 'ack'
if(!str) { emote(verb,0,0,0); return 1; }

// Ok, start the inspection of our str
array=explode(str," ");
// Check our stuff and put it in place
for(i=0;i<sizeof(array);i++)         {
if(find_player(array[i])) { target=array[i]; } else 
if(present(array[i],this_player())) { target=array[i]; } else 
if(get_adverb(array[i])) { adverb=array[i]; } else 
if(get_bodypart(array[i])) { bodypart=array[i]; } else 
{ write("Invalid adverb. ('"+array[i]+"')\n"); return 1; }
                             }

// Check if we send the emote to a player or if it's in-room
if(target)
if(present(target, environment(this_player()))) { 
emote(verb,target,adverb,bodypart); return 1;   } 
else      {
if(find_player(target)) remoteemote(verb,target,adverb,bodypart); 
return 1; }

// If we have no target but a bodypart, this_player is the default
if(!target && bodypart) target=lower_case(TPNAME); 
emote(verb,target,adverb,bodypart);    

return 1;
}

/*****************************************************************/

/* Only the first argument (verb) is cumpulsory, others an be 0's
 * 1 == the verb (fe. 'poke', 'ack at', 'wonder about') 
 * (the s that is seen by third parties is added in this fun)
 * 2 == the target (fe. 'nalle') 
 * 3 == the adverb (fe. 'zen-likely')
 * 4 == the bodypart (fe. 'nose') 
 */

status emote(string verb, string target, string adverb, string bodypart) {

string tmp1, tmp2; // example: tmp1==wonder tmp2==about
object target_ob;
int at_self,pseudo_target;
string orig_verb;

// Verb is obligatory
if(!verb) return 1;

// Just in case
at_self=0; pseudo_target=0;
orig_verb=lower_case(query_verb());

sscanf(verb,"%s %s",tmp1, tmp2);
if(target) target_ob=present(target,environment(this_player()));

// Load default adverbs, bparts and targets
if(!adverb) adverb=get_emote(tmp1,1);
if(!target) { target=get_emote(tmp1,2); pseudo_target=1; }
if(!bodypart) bodypart=get_emote(tmp1,3);

// Himself itself etc.
if(target == lower_case(this_player()->query_name())) {
at_self=1;
if(this_player()->query_gender()==0) target="itself";
if(this_player()->query_gender()==1) target="himself";
if(this_player()->query_gender()==2) target="herself";
                                                       } 
else { if(target && !pseudo_target) target=capitalize(target); }

// Temppidebug
write("!!!"+orig_verb+"\n");

// This is to make say work unaltered with the pseudo-targs
if(pseudo_target) target_ob=this_player();

// An emote with no target or other args
if(!target && !adverb && !bodypart) {
write("You "+tmp1+".\n");
say(TPNAME+" "+tmp1+"s.\n");
return 1;
                                     }
// Emote with target only (-> no default adverb has been assigned)
if(target && !adverb && !bodypart) {
if(at_self)
write("You "+verb+" yourself.\n");
  else {
write("You "+verb+" "+target+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" you.\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+".\n",target_ob); 
return 1;
                                    }
// Emote with adverb only
if(!target && adverb && !bodypart) {
write("You "+tmp1+" "+adverb+".\n");
say(TPNAME +" "+tmp1+"s "+adverb+".\n"); 
return 1;
                                    }
// Emote with target and adverb only
if(target && adverb && !bodypart) {
if(at_self)
write("You "+verb+" yourself "+adverb+".\n");
  else {
write("You "+verb+" "+target+" "+adverb+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" you "+adverb+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+adverb+".\n",target_ob); 
return 1;
                                    }
// Emote with target and and bodypart only
if(target && !adverb && bodypart) {
if(at_self) {
target=this_player()->query_possessive();
write("You "+verb+" your "+bodypart+".\n");
            }
  else {
target+="'s";
write("You "+verb+" "+target+" "+bodypart+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+bodypart+".\n",target_ob); 
return 1;
                                    }
// Emote with target, adverb and bodypart
if(target && adverb && bodypart) {
if(at_self) {
target=this_player()->query_possessive();
write("You "+verb+" your "+bodypart+" "+adverb+".\n");
            }
  else {
target+="'s";
write("You "+verb+" "+target+" "+bodypart+" "+adverb+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+" "+adverb+".\n");
       }
say(TPNAME +" "+tmp1+"s "+tmp2+" "+target+" "+bodypart+" "+adverb+".\n",target_ob); 
return 1;
                                    }
//
return 1;
}

/**********************************************************************/

status remoteemote
(string verb, string target, string adverb, string bodypart) {

string tmp1, tmp2; // example: tmp1==wonder tmp2==about
object target_ob;
int at_self;
string miuku;

if(!verb) return 1;
if(!target || (target==lower_case(TPNAME))) return 1;

sscanf(verb,"%s %s",tmp1, tmp2);
if(target) target_ob=find_player(target);

// Default adverbs and bodyparts (target has to be a player)
if(!adverb) adverb=get_emote(tmp1,1);
if(!bodypart) bodypart=get_emote(tmp1,3);
write("Default adverb: "+adverb+" Tmp1: "+tmp1+"\n");

target=capitalize(target);

// Only give a cyan bold 
if(target_ob->query_terminal()) { miuku=MIUKUBOLD; }
                           else { miuku="@";       }

// Check if the target is ignoring us
if(target_ob->query_ignore(lower_case(TPNAME)))
write("You fail to emote to "+target+". (Ignored)\n");

// Emote with target only (-> no default adverb has been assigned)
if(target && !adverb && !bodypart) {
write("Sent: You "+verb+" "+target+".\n");
tell_object(target_ob, miuku+TPNAME +" "+tmp1+"s "+tmp2+" you.\n");
return 1;
                                    }
// Emote with target and adverb only
if(target && adverb && !bodypart) {
write("Sent: You "+verb+" "+target+" "+adverb+".\n");
tell_object(target_ob, miuku+TPNAME +" "+tmp1+"s "+tmp2+" you "+adverb+".\n");
return 1;
                                    }
// Emote with target and and bodypart only
if(target && !adverb && bodypart) {
target+="'s";
write("Sent: You "+verb+" "+target+" "+bodypart+".\n");
tell_object(target_ob, miuku+TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+".\n");
return 1;
                                    }
// Emote with target, adverb and bodypart
if(target && adverb && bodypart) {
target+="'s";
write("Sent: You "+verb+" "+target+" "+bodypart+" "+adverb+".\n");
tell_object(target_ob, miuku+TPNAME +" "+tmp1+"s "+tmp2+" your "+bodypart+" "+adverb+".\n");
return 1;
                                    }
//
return 1;
}

/***********************************************************************/

/* Adverbs and bodyparts */

string get_adverb(string str) {
    if (str == "angrily") { return str; }
    if (str == "arrogantly") { return str; }
    if (str == "affectionately") { return str; }
    if (str == "awfully") { return str; }
    if (str == "audibly") { return str; }
    if (str == "badly") { return str; }
    if (str == "beautifully") { return str; }
    if (str == "boredly") { return str; }
    if (str == "boldly") { return str; }
    if (str == "brilliantly") { return str; }
    if (str == "briefly") { return str; }
    if (str == "bluntly") { return str; }
    if (str == "bitterly") { return str; }
    if (str == "calmly") { return str; }
    if (str == "cheerfully") { return str; }    
    if (str == "coldly") { return str; }
    if (str == "clearly") { return str; }
    if (str == "closely") { return str; }
    if (str == "comically") { return str; }
    if (str == "cruelly") { return str; }
    if (str == "cutely") { return str; }
    if (str == "decently") { return str; }
    if (str == "deeply") { return str; }
    if (str == "determinedly") { return str; }
    if (str == "diabolically") { return str; }
    if (str == "demonically") { return str; }
    if (str == "dirtily") { return str; }
    if (str == "dignifiedly") { return str; }
    if (str == "disgustingly") { return str; }
    if (str == "drily") { return str; }
    if (str == "dizzily") { return str; }
    if (str == "eerily") { return str; }
    if (str == "elegantly") { return str; }
    if (str == "enthousiastically") { return str; }
    if (str == "endlessly") { return str; }
    if (str == "erotically") { return str; }
    if (str == "evilly") { return str; }
    if (str == "fabulously") { return str; }
    if (str == "flegmatically") { return str; }
    if (str == "fearlessly") { return str; }
    if (str == "fearfully") { return str; }
    if (str == "firmly") { return str; }
    if (str == "fiercefully") { return str; }
    if (str == "frankly") { return str; }
    if (str == "funnily") { return str; }
    if (str == "frenetically") { return str; }
    if (str == "gently") { return str; }
    if (str == "girlishly") { return str; }
    if (str == "gleefully") { return str; }
    if (str == "happily") { return str; }
    if (str == "heartily") { return str; } 
    if (str == "heinously") { return str; }
    if (str == "hellishly") { return str; }
    if (str == "helplessly") { return str; }
    if (str == "hilariously") { return str; }
    if (str == "humbly") { return str; }
    if (str == "hungrily") { return str; }
    if (str == "horribly") { return str; }
    if (str == "hornily") { return str; }
    if (str == "idly") { return str; }
    if (str == "lazily") { return str; }
    if (str == "lovingly") { return str; }
    if (str == "magically") { return str; }
    if (str == "majestically") { return str; }
    if (str == "meanly") { return str; }
    if (str == "mercifully") { return str; }
    if (str == "mercilessly") { return str; }
    if (str == "mildly") { return str; }
    if (str == "mimically") { return str; }
    if (str == "merrily") { return str; }
    if (str == "menacingly") { return str; }
    if (str == "mightily") { return str; }
    if (str == "malevolently") { return str; }
    if (str == "meekly") { return str; }
    if (str == "miserably") { return str; }
    if (str == "mischievously") { return str; }
    if (str == "mockingly") { return str; }
    if (str == "mournfully") { return str; }
    if (str == "monstrously") { return str; }
    if (str == "musically") { return str; }
    if (str == "nicely") { return str; }
    if (str == "neatly") { return str; }
    if (str == "nonchalantly") { return str; }
    if (str == "obscurely") { return str; }
    if (str == "oddly") { return str; }
    if (str == "painfully") { return str; }
    if (str == "powerfully") { return str; }
    if (str == "pitifully") { return str; }
    if (str == "openly") { return str; }
    if (str == "promptly") { return str; }
    if (str == "patiently") { return str; }
    if (str == "pervertedly") { return str; }
    if (str == "philantropically") { return str; }
    if (str == "politely") { return str; }
    if (str == "philosophically") { return str; }
    if (str == "poetically") { return str; }
    if (str == "proudly") { return str; }
    if (str == "protectively") { return str; }
    if (str == "quizzically") { return str; }
    if (str == "quickly") { return str; }
    if (str == "repeatedly") { return str; }
    if (str == "rhetorically") { return str; }
    if (str == "remorsefully") { return str; }
    if (str == "sadly") { return str; }
    if (str == "scornfully") { return str; }
    if (str == "sarcastically") { return str; }
    if (str == "slowly") { return str; }
    if (str == "strangely") { return str; }
    if (str == "sheepishly") { return str; }
    if (str == "sensually") { return str; }
    if (str == "smoothly") { return str; }
    if (str == "sexily") { return str; }
    if (str == "satanically") { return str; }
    if (str == "scornfully") { return str; }
    if (str == "sceptically") { return str; }
    if (str == "shrilly") { return str; }
    if (str == "silently") { return str; }
    if (str == "sternly") { return str; }
    if (str == "skillfully") { return str; }
    if (str == "sinfully") { return str; }
    if (str == "subconsciously") { return str; }
    if (str == "subtly") { return str; }
    if (str == "tunefully") { return str; }
    if (str == "toothlessly") { return str; }
    if (str == "thoughtfully") { return str; }
    if (str == "vengefully") { return str; }
    if (str == "utterly") { return str; }
    if (str == "wholeheartedly") { return str; }
    if (str == "wrongfully") { return str; }
    if (str == "wetly") { return str; }
    if (str == "weirdly") { return str; }
    if (str == "wickedly") { return str; }
    if (str == "wimpily") { return str; }
    if (str == "wistfully") { return str; }
    if (str == "wondrously") { return str; }
    if (str == "wryly") { return str; }
    if (str == "wrathfully") { return str; }
    if (str == "xenophobically") { return str; }
    if (str == "zealously") { return str; }
    if (str == "zen-likely") { return str; }
    if (str == "zymotically") { return str; }
}

/* Bodyparts */

string get_bodypart(string str) {
    /* Approx. alphabetical order, please. */
    if (str == "abdomen") { return str; }
    if (str == "arm") { return str; }
    if (str == "ankle") { return str; }
    if (str == "back") { return str; }
    if (str == "butt") { return str; }
    if (str == "buttocks") { return str; }
    if (str == "breasts") { return genitalia(str); }
    if (str == "cheek") { return str; }
    if (str == "chin") { return str; }
    if (str == "cunt") { return genitalia(str); }
    if (str == "crotch") { return genitalia(str); }
    if (str == "chest") { return str; }
    if (str == "eye") { return str; }
    if (str == "elbow") { return str; }
    if (str == "fingers") { return str; }
    if (str == "finger") { return str; }
    if (str == "foot") { return str; }
    if (str == "groin") { return str; }
    if (str == "hand") { return str; }
    if (str == "head") { return str; }
    if (str == "jaw") { return str; }
    if (str == "knee") { return str; }
    if (str == "neck") { return str; }
    if (str == "nose") { return str; }
    if (str == "penis") { return genitalia(str); }
    if (str == "shoulder") { return str; }
    if (str == "slit") { return genitalia(str); }
    if (str == "stomach") { return str; }
    if (str == "tit") { return genitalia(str); }
    if (str == "tits") { return genitalia(str); }
    if (str == "toe") { return str; }
    if (str == "throat") { return str; }
    if (str == "thigh") { return str; }
    if (str == "toes") { return str; }
}

string genitalia(string str) {
 if((this_player()->query_gender())==1)  {
  if(str=="groin") return "groin";
  if(str=="penis") return "penis";
  if(str=="breasts") return "chest";         
  return "penis";                        }

 if((this_player()->query_gender())==2)  {
  if(str=="slit") return "slit";
  if(str=="cunt") return "cunt";
  if(str=="breasts") return "breasts";
  if(str=="tit") return "tit";          
  if(str=="tits") return "tits";          
  return "slit";                         }

 if((this_player()->query_gender())==0)  {
  if(str=="breasts") return "chest";
  return "crotch";                       }
}  

emotes() {
 if(!this_player()->check_condis())  { return 1; } 
 write("To list the available emotes type 'help emotes'.\n");
 return 1;
} 

adverbs() {
 if(!this_player()->check_condis())  { return 1; }
 write("To list the available adverbs and bodyparts type 'help adverbs'.\n");
 return 1;
}

