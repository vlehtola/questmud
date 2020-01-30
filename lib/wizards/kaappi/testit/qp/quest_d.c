/* return 0, if not valid. >0, if valid. given value is the reward in quest points */
/* value between 1-10? */

/* kaikki questit on reinc proofeja */
int validate_quest(string quest, int reinc_proof) {
  switch(quest) {
/* #### ADD QUESTS BELOW THIS LINE #### */

case "Help the baker": return 1;
// monsters/storagekeeper.c

case "Prime numbers": return 2;
/* /guilds/library/mathematician.c */

case "Realizing your lowly status": return 1;
/* /wizards/ahma/misc/sculpture.c */

case "Return the groundskeepers shovel": return 2;
/* /wizards/walla/areas/mg/mobs/keeper.c */

case "Give the dog a bone": return 1;
/* /wizards/walla/areas/mg/mobs/cur.c */

case "Pray to Angelina": return 2;
/* /wizards/walla/areas/mg/stuph/statue.c */

case "Slay the legendary brownie fighter Isak": return 3;
/* /wizards/moonstar/areas/brownie/monsters/isak.c  */

case "Kill the dweller shaman for Momo": return 5;
/* /wizards/rimber/cave/momo.c */

case "Find Sneek's missing earring": return 3;
/* /wizards/rimber/cave/sneek.c */

case "Help Gunthar finish his map": return 4;
/* /wizards/rimber/cave/gunthar.c */

case "Kill the dark dweller king": return 8;
/* /wizards/rimber/cave/thain.c */

case "Cheer Brutus up": return 11;
/* /wizards/rimber/cave/brutus.c */

case "Deliver the sealed letter": return 6;
/* /wizards/moonstar/areas/forest/monsut/drazil.c */

case "Help the priest of city Asgroth": return 10;
/* /wizards/moonstar/areas/asgroth/mobs/priest.c */

case "Find Azyltas ring from bazaar": return 3;
/* /wizards/moonstar/areas/asgroth/mobs/azyltas.c */

case "Find the monster of city sewers": return 2;
/* /wizards/moonstar/areas/asgroth/sewers/room32.c */

case "Find channelor's husband Marx": return 6;
/* /wizards/moonstar/areas/sewers/monsut/man.c */

case "Find the elder god 'Ra'Mos'Tot'": return 15;
/* /wizards/moonstar/areas/mosnotar/forest/eq/rose.c */

case "Moraloth path": return 3;
// /wizards/proge/moraloth/forest5

case "Bury Justin's heart in his wife's grave": return 7;
// /wizards/veron/areat/cotd/ceme1

// Kaappi area, added 26.3.2008 -Nalle

case "Return Dalana's book" : return 2;
// /wizards/kaappi/mine/mosat/lvahti.c
case "Help the dwarven miners" : return 2;
// /wizards/kaappi/mine/mosat/golem.c


case "Finding Terran's son": return 2;
/* /wizards/ahma/ice/mob/dwarf01.c */
case "Performing the dirty work for Serak": return 1;
/* /wizards/ahma/ice/mob/dwarf02.c */
case "Helping out the neighbors": return 3;
/* /wizards/ahma/ice/mob/dwarf05.c */

case "Devouring the carnivorous plants": return 7;
/* /wizards/ahma/orc/mob/carnplant04. */
case "Discover the pond's secret": return 4;
/* /wizards/ahma/orc/forest/for11.c */
case "Reviving the ancient elemental": return 9;
/* /wizards/ahma/orc/forest/sub10.c */

case "Find the secret exit in the Mansion": return 2;
/* /wizards/veron/areat/golem room16 */

case "Feed the woman in Gnael": return 4;
/* /wizards/jenny/gnael/mosut/hungry_woman.c */
case "It begins": return 5;
/* /wizards/jenny/gnael/mosut/amanda.c */
case "Closing the goal": return 2;
/* /wizards/jenny/gnael/mosut/mayor.c */
case "The final battle begins": return 5;
/* /wizards/jenny/gnael/rojut/heart.c */
case "Save the city of Gnael": return 12;
/* /wizards/jenny/gnael/mosut/feleodor.c */

case "Help Armin": return 3;
/* wizards/nalle/plateau/hut3 */

/* /wizards/rag/ruins/tunnel4 */
case "Vanquish the Lich King": return 20;

/* /wizards/jenny/linnake/mosut/iska_august.c */
case "Save the kingdom of Roxen" : return 15;
/* /wizards/jenny/linnake/mosut/poika_august.c */
case "Return August his belt" : return 2;
case "Deliver the letter from Susan" : return 4;
/* /wizards/jenny/mehta/rojut/bone.c */
case "Find the angry troll" : return 4;
/* /wizards/jenny/mehta/mosut/woman.c */
case "Help the woman in Toranth forest" : return 2;

/* /wizards/moonstar/areas/wasteland/monsut/captain.c */
case "Find Razel's missing ring" : return 5;
/* /wizards/moonstar/areas/forest/monsut/mayor.c */
case "End the brotherhood of fire and water" : return 20;

/* /wizards/gynter/element/gateway.c - Gynter's elementals */

case "Destroy the entrance to the fire plane": return 1;
case "Destroy the pillar to the air realm": return 1;
case "Destroy the gateway to the earth plane": return 1;
case "Destroy the entrance to the water plane": return 1;
case "Release the great spirit element": return 3;
case "Give vorpal blade to the lord of Air": return 4;
case "Give pouch to the stone elemental": return 4;
case "Return the key to the Fire Demon": return 4;
case "Return the icecube to the great white shark": return 4;

case "Return guard his sparkling sword": return 10;
/* /w/ahma/castle/rooms/area08 */

case "Kill the evil emperor": return 10;
/* /wizards/devil/area/mobit/man */

case "The death prevails": return 10;
/* /w/ahma/castle/rooms/area52 */
case "Discover markings": return 2;
/* /wizards/aarrgh/nyxi/ruin2.c */
case "Wake the mystical skeleton": return 2;
/* /w/a/n/mist2.c */
case "Open the flaming portal": return 6;
/*  /w/a/n/down1.c */
case "help woman with the mouse problem" : return 5;
/* (wizards/neophyte/farm/house.c") */
case "Bring man's watch back" : return 3;
/* (wizards/neophyte/forest/monst/man) */
case "Bring sheephide to goblin" : return 2;
/* (wizards/neophyte/city/monst/king) */
case "Find wolfrider den" : return 1;
/* (wizards/duncan/island/cave) */
case "Get inside the castle of Asgroth" : return 2;
/* (wizards/irmeli/castle/object/catapult) */
case "Return stoneworker's precious cross" : return 10;
/* (wizards/irmeli/castle/monsters/stoneworker) */
case "Return the head of the Executioner" : return 3;
/* (wizards/irmeli/castle/monsters/etowerguard) */
/* (wizards/irmeli/castle/monsters/wtowerguard) */
case "Lure the Enchantress" : return 10;
/* (wizards/irmeli/valley/object/head) */
case "Bring the heart to the Knight" : return 10;
/* (wizards/irmeli/valley/monsters/knight) */
case "Find the ancient crab": return 2;
/* (wizards/torspo/areat/ogre/cave) */
case "Find the secret hideout in the Church": return 3;
/* (guilds/channels/r17) */
case "Return painting to the hobbit gardener": return 3;
/* (wizards/bulut/forl/monsters/gardener) */
case "Secret guild of the Acrobats": return 2;
/* (guilds/fighter/acrocitizen) */
case "Return the Holy Cross to the priest": return 6;
/* (wizards/grathlek/area1/monsies/mopriest) */
case "Open curtains in paladin training area": return 1;
/* (wizards/grathlek/area1/eroom12) */

/* /wizards/luminarc/wizcastle/room0.c -- jossain */
case "Return the Farnax's soulstone": return 4;

/* /wizards/gynter/darke/entrance.c (Gynter) */
/* /wizards/gynter/darke/eq/book.c */
/* /wizards/gynter/darke/city/hall/phall.c */

case "Read the Book of Laws": return 5;
case "Find the book of laws": return 3;

/* /wizards/rag/elf/monsters/celebmir.c */
case "Return Celebmir's amulet": return 5;

case "Cross the river in the forest": return 1;
/* (wizards/irmeli/bwp/room8) */
case "Lure the witch out from the bushes": return 8;
/* (wizards/irmeli/bwp/eq/cloak) */
case "Find the secret hobbit gallery": return 3;
/* (wizards/irmeli/area2/ruum28) tuned. //Celtron */
case "Slay Darvox": return 15;
/* (wizards/nalle/area/monsters/mayor) */
case "Enter the magic mirror": return 3;
/* (wizards/nalle/area/darvroome) */
case "Help the wounded man": return 15;
/* (wizards/nalle/jerusalem/eq/varjo) */
case "Rescue the little kitten": return 8;
/* (wizards/nalle/jerusalem/monsters/towlady) */
case "Give Zephaniah a flask of Holy Water": return 4;
/* (wizards/nalle/jerusalem/monsters/zephaniah) */
case "Release a lady in David's Tower": return 7;
/* (wizards/nalle/jerusalem/dav2h) */
case "Return Layla's ring to the old man": return 5;
/* (wizards/shadow/Wolf/monsters/oldman) */
case "Bring the head of the seamonster to the Lizard King": return 12;
/* (wizards/siki/lizard/monsters/king) */
case "Dive into the cold water": return 2;
/* (wizards/siki/lizard/dock2) */
case "Help alchemist with his mission": return 10;
/* (wizards/walla/area/monsters/alchemist) */
case "Bring wolf head to Lalli": return 2;
/* (wizards/torspo/areat/gnomes/monsters/lalli) */
case "Slay Leb-Kamar": return 15;
/* (wizards/walla/jericho/mobs/leb.c) */
case "se "Bug report (worth 4)": return 4;
/* (A substantial, important bug report) */
case "Feed Monkey": return 8;
/* Feed the monkey - An event worth questpoints! */
case "Win the treasure hunt": return 4;
/* (/wizards/rag/events/thunt/master.c) */
case "Get rid of Zadax": return 7;
/* (/wizards/rag/events/teleport/zadax.c) */
  }
 return 0;
}

