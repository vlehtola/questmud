/* The new emote system for QuestMud by Nalle 31.5.2002 */

#include <ansi.h>
#define TPNAME this_player()->query_name()
#define MIUKU "@"+CYAN_F+TPNAME+OFF
#define ALPHA "/daemons/alpha"

inherit "/daemons/soul_data";

string *e_array;
mapping e_map;

status emote(string verb, string target, string adverb, string bodypart);
status remoteemote(string verb, string target, string adverb, string bodypart);
status parse(string str);
string get_adverb(string str);
string get_bodypart(string str, object ob);
string get_emote(string str);
string genitalia(string str, object ob);
status list_emotes();
status list_adverbs();

get() { return 1; }

drop() { return 1; }

id(str) { return str == "soul_object"; }

long() {
    write("It is transparent.\n");
}

init() {
string poss;
poss=this_player()->query_possessive();

e_map=([
  "ack":"ack";"acks";"at";0;0;0;0;0,
  "agree":"agree";"agrees";"with";0;0;0;0;0,
  "ah":"go 'Ah'";"goes 'Ah'";"at";0;0;0;0;0,
  "apologize":"apologize";"apologizes";"to";0;0;0;0;0,
  "applaud":"applaud";"applauds";"at";0;0;0;0;0,
  "argh":"go 'Aarrgghh!'";"goes 'Aarrgghh!'";"at";0;0;0;0;0,
  "bark":"bark";"barks";"at";0;0;"like a dog";0;0,
  "beg":"beg";"begs";0;"shamelessly";0;0;0;0,
  "belch":"belch";"belches";0;"rudely";0;0;0;0,
  "bleed":"bleed";"bleeds";"on";0;0;0;0;0,
  "blink":"blink";"blinks";"at";0;0;0;0;0,
  "blush":"blush";"blushes";"at";"shyly";0;0;0;0,
  "beep":"beep";"beeps";0;"playfully";"nose";0;"on the";1,
  "bonk":"bonk";"bonks";0;"barbarically";"head";0;"on the";1,
  "boo":"boo";"boos";"at";"disappointedly";0;0;0;0,
  "bore":"bore";"bores";0;"unwittingly";0;0;0;1,
  "bored":"seem bored";"seems bored";"by";0;0;0;0;0,
  "bounce":"bounce";"bounces";"around";"joyfully";0;0;0;0,
  "bow":"bow";"bows";"to";"gracefully";0;0;0;0,
  "burp":"burp";"burps";"at";"rudely";0;0;0;0,
  "cackle":"cackle";"cackles";"at";"gleefully";0;0;0;0,
  "caress":"caress";"caresses";0;"fondly";0;0;0;0,
  "ccl":"couldn't care less";"couldn't care less";"about";0;0;0;0;0,
  "cheer":"cheer";"cheers";"at";"enthusiastically";0;0;0;0,
  "chuckle":"chuckle";"chuckles";"at";"good-heartedly";0;0;0;0,
  "clap":"clap";"claps";"at";"appreciatively";0;0;0;0,
  "click":"click your tongue";"clicks "+poss+" tongue";"at";"disapprovingly";0;0;0;0,
  "comfort":"comfort";"comforts";0;0;0;0;0;1,
  "confuse":"confuse";"confuses";0;"stealthily";0;0;0;0,
  "confused":"seem confused";"seems confused";"by";0;0;0;0;0,
  "congratulate":"congratulate";"congratulates";0;"wholeheartedly";0;0;0;0,
  "cough":"cough";"coughs";"at";"noisily";0;0;0;0,
  "croak":"croak";"croaks";"at";0;0;0;0;0,
  "cry":"cry";"crys";"at";"inconsolably";0;0;0;0,
  "cuddle":"cuddle";"cuddles";0;"fondly";0;0;0;1,
  "curse":"curse";"curses";"at";"wrathfully";0;0;0;0,
  "curtsey":"curtsey";"curtseys";"to";"gracefully";0;0;0;0,
  "dance":"dance";"dances";"with";"merrily";0;0;0;0,
  "disagree":"disagree";"disagrees";"with";0;0;0;0;0,
  "dream":"dream";"dreams";"about";"longingly";0;0;0;1,
  "drool":"drool";"drools";"at";"uncontrollably";0;0;0;0,
  "eww":"go 'Eww!'";"goes 'Eww!'";"at";0;0;0;0;0,
  "eep":"eep";"eeps";"at";"fearfully";0;0;0;0,
  "evvk":"couldn't care less";"couldn't care less";"about";0;0;0;0;0,
  "fart":"fart";"farts";"at";"cheesily";0;0;0;0,
  "fear":"fear";"fears";0;0;0;0;0;1,
  "flex":"flex your muscles";"flexes "+poss+" muscles";"at";0;0;0;0;0,
  "flirt":"flirt";"flirts";"with";"openly";0;0;0;0,
  "fondle":"fondle";"fondles";0;"lustily";0;0;0;1,
  "french":"suck";"sucks";"on";"passionately";"tongue";0;0;1,
  "frown":"frown";"frowns";"at";"disapprovingly";0;0;0;0,
  "gasp":"gasp";"gasps";"at";"astonishedly";0;0;0;0,
  "giggle":"giggle";"giggles";"at";"merrily";0;0;0;0,
  "gigglesnort":"gigglesnort";"gigglesnorts";"at";"lamely";0;0;0;0,
  "glare":"glare";"glares";"at";"angrily";0;0;0;0,
  "gnn":"go 'Gnnn'";"goes 'Gnnn'";"at";0;0;0;0;0,
  "greet":"greet";"greets";0;0;0;"everyone";0;0,
  "grin":"grin";"grins";"at";"widely";0;0;0;0,
  "groan":"groan";"groans";"at";"loudly";0;0;0;0,
  "grope":"grope";"gropes";0;0;0;0;0;1,
  "growl":"growl";"growls";"at";0;0;"like a beast";0;0,
  "grr":"go 'GRR'";"goes 'GRR'";"at";0;0;0;0;0,
  "grrmrr":"go 'GRRMRR'";"goes 'GRRMRR'";"at";0;0;0;0;0,
  "gurgle":"gurgle";"gurgles";"at";"toothlessly";0;0;0;0,
  "hail":"hail";"hails";0;0;0;0;0;1,
  "heh":"go 'Heh'";"goes 'Heh'";"at";0;0;0;0;0,
  "hiccup":"hiccup";"hiccups";"at";"uncontrollably";0;0;0;0,
  "hmm":"hmm";"hmms";"at";"thoughtfully";0;0;0;0,
  "hmpf":"hmpf";"hmpfs";"at";0;0;0;0;0,
  "hooray":"yell 'Hooray!'";"yells 'Hooray!'";"at";0;0;0;0;0,
  "hug":"hug";"hugs";0;"warmly";0;0;0;1,
  "huggle":"huggle";"huggles";0;"softly";0;0;0;1,
  "hum":"hum a little tune";"hums a little tune";"at";0;0;0;0;0,
  "kick":"kick";"kicks";0;0;"knee";0;"in the";1,
  "kiss":"kiss";"kisses";0;"fondly";0;0;0;1,
  "knee":"knee";"knees";0;0;"crotch";0;"in the";1,
  "laugh":"laugh";"laughs";"at";"heartily";0;0;0;0,
  "lick":"lick";"licks";0;0;0;0;0;1,
  "lol":"laugh out loud";"laughs out loud";"at";0;0;0;0;0,
  "love":"love";"love";0;"deeply";0;0;0;1,
  "lust":"are full of lust";"seems full of lust";"for";0;0;0;0;0,
  "mmm":"go 'mmm'";"goes 'mmmm'";"at";0;0;0;0;0,
  "meep":"meep";"meeps";"at";0;0;0;0;0,
  "moan":"moan";"moans";"at";0;0;0;0;0,
  "mourn":"mourn";"mourns";0;"deeply";0;0;0;0,
  "moo":"you 'MOO' like a cow";"MOOs like a cow";"at";0;0;0;0;0,
  "mrr":"go 'MRR'";"goes 'MRR'";"at";0;0;0;0;0,
  "mrrgrr":"go 'MRRGRR'";"goes 'MRRGRR'";"at";0;0;0;0;0,
  "muah":"MUAH";"MUAHs";"at";0;0;0;0;0,
  "nibble":"nibble";"nibbles";"on";0;"ear";0;0;1,
  "no":"say 'no'";"says 'no'";"at";"clearly";0;0;0;0,
  "noo":"wail 'Nooo-oo!'";"wails 'Nooo-oo!'";"at";"insanely";0;0;0;0,
  "nod":"nod";"nods";"at";"solemnly";0;0;0;0,
  "nodnod":"nod twice in agreement";"nods twice in agreement";"at";0;0;0;0;0,
  "nog":"nog";"nogs";"at";"noggingly";0;0;0;0,
  "nuuh":"go 'nuuh'";"goes 'nuuh'";"at";0;0;0;0;0,
  "observe":"observe";"observes";0;"closely";0;0;0;0,
  "ooo":"go 'OK'";"goes 'OK'";"at";0;0;0;0;0,
  "ooo":"go 'Oooo'";"goes 'Oooo'";"at";0;0;0;0;0,
  "oops":"go 'Oops'";"goes 'Oops'";"at";0;0;0;0;0,
  "ouch":"go 'Ouch!'";"goes 'Ouch!'";"at";0;0;0;0;0,
  "pat":"pat";"pats";0;0;"head";0;"on the";1,
  "pet":"pet";"pets";0;0;0;0;0;1,
  "piss":"piss";"pisses";"on";0;0;"in the corner";0;0,
  "pok":"pok";"poks";0;0;0;0;0;0,
  "poke":"poke";"pokes";0;0;"ribs";0;"in the";1,
  "pout":"pout";"pouts";"at";0;0;0;0;0,
  "puke":"puke";"pukes";"on";0;0;"on the floor";0;0,
  "punch":"punch";"punches";0;0;"nose";0;"in the";1,
  "puppy":"make puppy dog eyes";"makes puppy dog eyes";"at";0;0;0;0;1,
  "purr":"purr";"purrs";"at";"softly";0;0;0;0,
  "puuh":"puuh";"puuhs";"at";0;0;0;0;0,
  "rofl":"roll on the floor laughing";"rolls on the floor laughing";"at";0;0;0;0;0,
  "ruffle":"ruffle";"ruffles";0;"playfully";"hair";0;0;1,
  "sad":"seem sad";"seems sad";"at";0;0;0;0;0,
  "scare":"try to scare";"tries to scare";0;"spookily";0;0;0;1,
  "scratch":"scratch";"scratches";0;0;"head";0;0;0,
  "scream":"scream";"screams";"at";"loudly";0;0;0;0,
  "shake":"shake your head at";"shakes "+poss+" head";"at";0;0;0;0;0,
  "shiver":"shiver";"shivers";"at";"fearfully";0;0;0;0,
  "shrug":"shrug";"shrugs";"at";"helplessly";0;0;0;0,
  "sigh":"sigh";"sighs";"at";"deeply";0;0;0;0,
  "sing":"sing";"sings";"at";"beautifully";0;0;0;0,
  "slap":"slap";"slaps";0;0;"cheek";0;"on the";1,
  "slobber":"slobber";"slobbers";"on";"repulsively";0;0;0;0,
  "smirk":"smirk";"smirks";"at";"wryly";0;0;0;0,
  "smile":"smile";"smiles";"at";"happily";0;0;0;0,
  "snap":"snap your fingers";"snaps "+poss+" fingers";"at";0;0;0;0;0,
  "sneeze":"sneeze";"sneezes";"at";0;0;0;0;0,
  "snicker":"snicker";"snickers";"at";0;0;0;0;0,
  "sniff":"sniff";"sniffs";"at";"sadly";0;0;0;0,
  "sniffle":"sniffle";"sniffles";"at";"pitifully";0;0;0;0,
  "snore":"snore";"snores";"at";0;0;0;0;0,
  "snuggle":"snuggle";"snuggles";"up to";0;0;0;0;1,
  "sob":"sob";"sobs";"on";"unconsolably";0;0;0;0,
  "spank":"spank";"spanks";0;"forcefully";0;0;0;1,
  "spit":"spit";"spits";"on";"defiantly";0;0;0;0,
  "squeeze":"squeeze";"squeezes";0;0;0;0;0;0,
  "stare":"stare";"stares";"at";0;0;"into the horizon";0;0,
  "strip":"start stripping";"starts stripping";"for";"erotically";0;0;0;0,
  "suck":"suck";"sucks";"on";0;"finger";0;0;1,
  "sulk":"sulk";"sulks";"at";0;0;0;0;0,
  "tap":"tap your foot";"taps "+poss+" foot";"at";"impatiently";0;0;0;0,
  "taunt":"taunt";"taunts";0;0;0;0;0;1,
  "tease":"tease";"teases";0;"playfully";0;0;0;1,
  "thank":"thank";"thanks";0;0;"gratefully";"everyone";0;0,
  "think":"think";"thinks";"about";0;0;"about some pressing matter";0;0,
  "tickle":"tickle";"tickles";0;"playfully";0;0;0;1,
  "touch":"touch";"touches";0;"arousingly";0;0;0;1,
  "tremble":"tremble";"trembles";"at";"fearfully";0;"with fear";0;0,
  "tsk":"go 'tsk'";"goes 'tsk'";"at";0;0;0;0;0,
  "twiddle":"twiddle your thumbs";"twiddles "+poss+" thumbs";"at";0;0;0;0;0,
  "wait":"wait";"waits";"for";0;0;0;0;0,
  "wake":"try to wake";"tries to wake";0;0;0;0;0;0,
  "wave":"wave";"waves";"at";"happily";0;0;0;0,
  "whine":"whine";"whines";"at";0;0;"about life in general";0;0,
  "whistle":"whistle";"whistles";"at";"appreciatively";0;0;0;0,
  "wiggle":"wiggle your butt";"wiggles "+poss+" butt";"at";0;0;0;0;0,
  "wonder":"wonder";"wonders";"about";0;0;"about this and that";0;0,
  "worship":"worship";"worships";0;0;0;"Nalle reverently";0;0,
  "wink":"wink";"winks";"at";"suggestively";0;0;0;0,
  "wow":"go 'Wow'";"goes 'Wow'";"at";0;0;0;0;0,
  "yawn":"yawn";"yawns";"at";"tiredly";0;0;0;0,
  "yes":"say 'Yes'";"says 'Yes'";"at";"plainly";0;0;0;0,
  "yodel":"yodel";"yodels";"at";"tunefully";0;0;0;0
 ]);

    e_array=m_indices(e_map);

    add_action("parse", "",1);
    add_action("list_emotes", "emotes");
    add_action("list_adverbs", "adverbs");
}

/****************************************************************/

string get_emote(string str) {
int i;
for(i=0;i<sizeof(e_array);i++) {
if(str==e_array[i]) return e_array[i];
                                  }
return 0;
}

/*******************************************************************/

status parse(string str) {
string verb,target,adverb,bodypart,temp;
string *array;
int i,n;

// Check that the command is an emote, else return 0
verb=get_emote(query_verb());
if(!verb) return 0;

// An emote with no string->call it.
if(!str) { 
           if(!target && e_map[verb,7]) 
           { write("This emote requires a target.\n"); return 1; }
           emote(verb,target,adverb,bodypart);    
           return 1; 
         }

// Ok, start the inspection of our str
if(!str) return 1;
array=explode(str," ");
// Check our stuff and put it in place
for(i=0;i<sizeof(array);i++)         {
if(find_player(array[i])) target=array[i];  else
if(present(array[i],environment(this_player()))) target=array[i]; else  
if(present(array[i],this_player())) target=array[i]; else  
if(get_bodypart(array[i],0)) bodypart=array[i]; else  
if(get_adverb(array[i])) adverb=get_adverb(array[i]); else
{ write("Invalid adverb. ('"+array[i]+"')\n"); return 1; }
                                     }

// Send the emote like a tell if appropriate
if(target)
if(!present(target, environment(this_player())) && find_player(target)) 
{ remoteemote(verb,target,adverb,bodypart); return 1; }

// Check if the emote requires a target (non-0 at e_map[verb,7]) 
if(!target && e_map[verb,7]) 
{ write("This emote requires a target.\n"); return 1; }

emote(verb,target,adverb,bodypart);    

return 1;
}

/*****************************************************************/

/* Only the first argument (verb) is compulsory, others can be 0's
 * 1 == the verb (fe. 'poke', 'ack at', 'wonder about') 
 * (the s that is seen by third parties is added in this fun)
 * 2 == the target (fe. 'nalle') 
 * 3 == the adverb (fe. 'zen-likely')
 * 4 == the bodypart (fe. 'nose') 
 */

status emote(string verb, string target, string adverb, string bodypart) {

object target_ob;
int at_self,pseudo_target;
string prep,bprep,own_ob;

// Verb is obligatory
if(!verb) return 1;

// Set the target object for says
if(target) target_ob=present(target,environment(this_player())); 
if(target && !target_ob) 
{ target_ob=present(target,this_player()); pseudo_target=2; }

// Load default adverbs, bparts and targets
if(!adverb && e_map[verb,3]) adverb=e_map[verb,3];
if(!bodypart && e_map[verb,4]) bodypart=e_map[verb,4];
if(!target && e_map[verb,5]) { target=e_map[verb,5]; pseudo_target=3; }

// Our pseudotarget action (e_map5/inanimate objects)
if(target) {
if(!target_ob) pseudo_target=3; 
else {
if(!living(target_ob)) bodypart=0;
if(!find_player(target)) pseudo_target=1; else pseudo_target=0;
if(present(target,this_player())) pseudo_target=2;
     }
           }

// If we have no target but a bodypart, this_player is the default
if(!target && bodypart) { target=lower_case(TPNAME); target_ob=this_player(); }

// This is here because a preposition is not obligatory
// And the pseudo_target 3 (from mapping) is much more handy without preps
if(e_map[verb,2]) { prep=" "+e_map[verb,2]+" "; } else { prep=" "; }
if(pseudo_target==3) { prep=" "; bodypart=0; }

// Some emotes have special prepositions for bodyparts (0 == "'s")
if(bodypart) if(!e_map[verb,6]) bprep="'s"; else bprep=" "+e_map[verb,6];

// Himself itself etc.
if(target == lower_case(this_player()->query_name())) {
at_self=1;
if(this_player()->query_gender()==0) target="itself";
if(this_player()->query_gender()==1) target="himself";
if(this_player()->query_gender()==2) target="herself";
                                                       } 
else { if(target && !pseudo_target) target=capitalize(target); }

// This is to make say work unaltered with the pseudo-tgts, and 
// make the target short() if an object
if(pseudo_target)       { 
if(target_ob) 
if(present(target,this_player())) own_ob=" "+this_player()->query_possessive()+" "; else own_ob="";
target=lower_case(target_ob->short()); 
target_ob=this_player();   
                        }

// Remove 'a' or 'an' from in front if 'his'/etc is to be added
if(pseudo_target==2) sscanf(target,"a %s",target);
if(pseudo_target==2) sscanf(target,"an %s",target);

// A final check for gender dependent bodyparts 
if(bodypart) bodypart=get_bodypart(bodypart, target_ob);

// An emote with no target or other args
if(!target && !adverb && !bodypart) {
write("You "+e_map[verb,0]+".\n");
say(TPNAME+" "+e_map[verb,1]+".\n");
return 1;
                                     }
// Emote with target only (-> no default adverb has been assigned)
if(target && !adverb && !bodypart) {
if(at_self)
write("You "+e_map[verb,0]+prep+"yourself.\n");
  else {
write("You "+e_map[verb,0]+prep+target+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+e_map[verb,1]+prep+"you.\n");
       }
say(TPNAME +" "+e_map[verb,1]+prep+target+".\n",target_ob); 
return 1;
                                    }
// Emote with adverb only
if(!target && adverb && !bodypart) {
write("You "+e_map[verb,0]+" "+adverb+".\n");
say(TPNAME +" "+e_map[verb,1]+" "+adverb+".\n"); 
return 1;
                                    }
// Emote with target and adverb only
if(target && adverb && !bodypart) {
if(at_self)
write("You "+e_map[verb,0]+prep+"yourself "+adverb+".\n");
  else {
write("You "+e_map[verb,0]+prep+target+" "+adverb+".\n");
if(!pseudo_target)
tell_object(target_ob, TPNAME +" "+e_map[verb,1]+prep+"you "+adverb+".\n");
       }
say(TPNAME +" "+e_map[verb,1]+prep+target+" "+adverb+".\n",target_ob); 
return 1;
                                    }
// Emote with target and and bodypart only
if(target && !adverb && bodypart) {
if(at_self) {
if(!e_map[verb,6]) bprep=" "; else bprep="self "+e_map[verb,6]+" ";
write("You "+e_map[verb,0]+prep+"your"+bprep+bodypart+".\n");
            }
  else {
write("You "+e_map[verb,0]+prep+target+bprep+" "+bodypart+".\n");
if(!pseudo_target) {
if(!e_map[verb,6]) bprep="r "; else bprep=" "+e_map[verb,6]+" ";
tell_object(target_ob, TPNAME +" "+e_map[verb,1]+prep+"you"+bprep+bodypart+".\n");
                   }
       }
if(!e_map[verb,6]) 
{ bprep="'s "; if(at_self) { target=this_player()->query_possessive(); bprep=" "; } } 
else { bprep=" "+e_map[verb,6]+" "; }
say(TPNAME +" "+e_map[verb,1]+prep+target+bprep+bodypart+".\n",target_ob); 
return 1;
                                    }
// Emote with target, adverb and bodypart
if(target && adverb && bodypart) {
if(at_self) {
if(!e_map[verb,6]) bprep=" "; else bprep="self "+e_map[verb,6]+" ";
write("You "+e_map[verb,0]+prep+"your"+bprep+bodypart+" "+adverb+".\n");
            }
  else {
write("You "+e_map[verb,0]+prep+target+bprep+" "+bodypart+" "+adverb+".\n");
if(!pseudo_target)
if(!e_map[verb,6]) bprep="r "; else bprep=" "+e_map[verb,6]+" ";
tell_object(target_ob, TPNAME +" "+e_map[verb,1]+prep+"you"+bprep+bodypart+" "+adverb+".\n");
       }
if(!e_map[verb,6]) 
{ bprep="'s "; if(at_self) { target=this_player()->query_possessive(); bprep=" "; } } 
else { bprep=" "+e_map[verb,6]+" "; }
say(TPNAME +" "+e_map[verb,1]+prep+target+bprep+bodypart+" "+adverb+".\n",target_ob); 
return 1;
                                    }
return 1;
}

/**********************************************************************/

status remoteemote
(string verb, string target, string adverb, string bodypart) {

object target_ob;
string miuku;
string prep,bprep;

if(!verb) return 1;
if(!target || (target==lower_case(TPNAME))) return 1;
target_ob=find_player(target);

// This is here because a preposition is not obligatory
if(e_map[verb,2]) prep=" "+e_map[verb,2]; else prep="";

// Default adverbs and bodyparts (target has to be a player)
if(!adverb && e_map[verb,3]) adverb=e_map[verb,3];
if(!bodypart && e_map[verb,4]) bodypart=e_map[verb,4];

// Some emotes have special prepositions for bodyparts (0 == "'s")
if(bodypart) if(!e_map[verb,6]) bprep="'s"; else bprep=" "+e_map[verb,6];

// Capitalize target's name
target=capitalize(target);

// Only give a cyan miuku to ansi terminals
if(target_ob->query_terminal()) { miuku=MIUKU; }
                           else { miuku="@"+TPNAME;       }

// Check if the target is ignoring us
if(target_ob->query_ignore(lower_case(TPNAME))) {
write("You fail to emote to "+target+". (Ignored)\n");
return 1;                                       }

// Emote with target only (-> no default adverb has been assigned)
if(target && !adverb && !bodypart) {
write("Sent: You "+e_map[verb,0]+prep+" "+target+".\n");
tell_object(target_ob, miuku +" "+e_map[verb,1]+prep+" you.\n");
return 1;
                                    }
// Emote with target and adverb only
if(target && adverb && !bodypart) {
write("Sent: You "+e_map[verb,0]+prep+" "+target+" "+adverb+".\n");
tell_object(target_ob, miuku +" "+e_map[verb,1]+prep+" you "+adverb+".\n");
return 1;
                                    }
// Emote with target and and bodypart only
if(target && !adverb && bodypart) {
target+=bprep;
if(!e_map[verb,6]) bprep="r "; else bprep=" "+e_map[verb,6]+" ";
write("Sent: You "+e_map[verb,0]+prep+" "+target+" "+bodypart+".\n");
tell_object(target_ob, miuku +" "+e_map[verb,1]+prep+" you"+bprep+bodypart+".\n");
return 1;
                                    }
// Emote with target, adverb and bodypart
if(target && adverb && bodypart) {
target+=bprep;
if(!e_map[verb,6]) bprep="r "; else bprep=" "+e_map[verb,6]+" ";
write("Sent: You "+e_map[verb,0]+prep+" "+target+" "+bodypart+" "+adverb+".\n");
tell_object(target_ob, miuku +" "+e_map[verb,1]+prep+" you"+bprep+bodypart+" "+adverb+".\n");
return 1;
                                    }

 
return 1;
}

/***********************************************************************/

/* Matching */
// 3 first
string match_string(string str, string *verbs) {
  int alpha, match, uplimit, downlimit, old_match, i;

// 1st check for perfect match
for(i=0;i<sizeof(verbs);i++) if(str==verbs[i]) return str;

  alpha = ALPHA->get_value(str,3);
  uplimit = sizeof(verbs);
  downlimit = 0; old_match = 1;

  /* binaarihakusysteemi */
  while(match != old_match) {
    old_match = match;
    match = ALPHA->get_value(verbs[(downlimit+uplimit)/2], 3);
/* // Debuggink
if(this_player()->query_wiz()) 
write("matching.."+verbs[(downlimit+uplimit)/2]+": "+downlimit+"/"+uplimit+", "+match+"("+alpha+")\n");
 */
    if(match == alpha)
      return verbs[(downlimit+uplimit)/2];
    else if(match < alpha)
      downlimit = (downlimit+uplimit)/2;
    else
      uplimit = (downlimit+uplimit)/2;
  }
  return 0;
}

/*****************************************************************/

/* Adverbs */

string get_adverb(string str) {
return match_string(str,adverbs);
}

/* Bodyparts */

string get_bodypart(string str, object ob) {
    /* Approx. alphabetical order, please. */
    if (str == "arm") { return str; }
    if (str == "ankle") { return str; }
    if (str == "back") { return str; }
    if (str == "butt") { return str; }
    if (str == "breasts") { return genitalia(str,ob); }
    if (str == "cheek") { return str; }
    if (str == "chin") { return str; }
    if (str == "cunt") { return genitalia(str,ob); }
    if (str == "crotch") { return genitalia(str,ob); }
    if (str == "chest") { return str; }
    if (str == "eye") { return str; }
    if (str == "elbow") { return str; }
    if (str == "fingers") { return str; }
    if (str == "finger") { return str; }
    if (str == "foot") { return str; }
    if (str == "groin") { return str; }
    if (str == "hair") { return str; }
    if (str == "hand") { return str; }
    if (str == "head") { return str; }
    if (str == "jaw") { return str; }
    if (str == "knee") { return str; }
    if (str == "neck") { return str; }
    if (str == "nose") { return str; }
    if (str == "penis") { return genitalia(str,ob); }
    if (str == "ribs") { return str; }
    if (str == "shoulder") { return str; }
    if (str == "slit") { return genitalia(str,ob); }
    if (str == "stomach") { return str; }
    if (str == "tit") { return genitalia(str,ob); }
    if (str == "tits") { return genitalia(str,ob); }
    if (str == "toe") { return str; }
    if (str == "toes") { return str; }
    if (str == "throat") { return str; }
    if (str == "thigh") { return str; }
}

/*************************************************************************/

string genitalia(string str, object ob) {
if(!ob) return str;

 if((ob->query_gender())==1)            {
  if(str=="groin") return "groin";
  if(str=="penis") return "penis";
  if(str=="breasts") return "chest";         
  if(str=="tit") return "chest";          
  if(str=="tits") return "chest";          
  return "penis";                        }

 if((ob->query_gender())==2)  {
  if(str=="slit") return "slit";
  if(str=="cunt") return "cunt";
  if(str=="breasts") return "breasts";
  if(str=="tit") return "tit";          
  if(str=="tits") return "tits";          
  return "slit";              }

 if((ob->query_gender())==0)  {
  if(str=="breasts") return "chest";
  if(str=="tit") return "chest";          
  if(str=="tits") return "chest";          
  return "crotch";            }

}
  

/****************************************************************/

status list_emotes() {
 int i,n;
 string temp, result;
 object pager;
// Check that he is ok
if(!this_player()->check_condis())  { return 1; } 

result="\nEmotes currently in use :\n\n";
for(i=0;i<sizeof(e_array);i++) {
temp=e_array[i];
while(strlen(temp)<21) temp+=" ";
result+=temp; if(!(++n%3)) result+="\n";
                                  }
if(n%3) result+="\n"; result+="\nA total of "+i+" emotes listed.\n";

pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(result);

return 1;
}

/****************************************************************/

status list_adverbs() {
 int i,n;
 string temp, result;
 object pager;
// Check that he is ok
if(!this_player()->check_condis())  { return 1; } 

result="\nAdverbs currently in use :\n\n";
for(i=0;i<sizeof(adverbs);i++) {
temp=adverbs[i];
while(strlen(temp)<21) temp+=" ";
result+=temp; if(!(++n%3)) result+="\n";
                                  }
if(n%3) result+="\n"; result+="\nA total of "+i+" adverbs listed.\n";

pager = clone_object("/daemons/pager");
pager->move(this_player());
pager->page(result);

return 1;
}

/****************************************************************/

