mapping guilds, multiguilds, subguilds;

mapping query_guilds() {
  return guilds;
}

mapping query_multiguilds() {
  return multiguilds;
}

mapping query_subguilds() {
  return subguilds;
}

void reset(status arg) {
  guilds = ([ "fighter":"Fighters";"/guilds/fighter/fighter";"/guilds/fighter/description";0;0,
              "mage":"Apprentice Mages";"/guilds/mage/apprmage";"/guilds/mage/description";0;0,
              "necromancer":"necromancers";"/guilds/necro/base_guild";"/guilds/necro/description";1000000;0,
              "cleric":"Apprentice clerics";"/guilds/channel/appr_cleric";"/guilds/channel/description";0;0,
              "psionic":"Psionicists";"/guilds/psi/psiguild";"/guilds/psi/description";0;0,
              "warlock":"Warlocks";"/guilds/warlock/warlock";"/guilds/warlock/description";0;0,
              "martial artist":"Martial artist";"/guilds/artists/base_guild";"/guilds/artists/description";0;0,
           ]);

  multiguilds = ([(string)
"battlemage":"mage";"fighter",
"paladin":"fighter";"cleric",
"abjurer":"mage";"cleric",
 ]);

/*
  multiguilds = ([(string)
"battlemage":"mage";"fighter",
"chaos knight":"fighter";"necromancer",
"paladin":"fighter";"cleric",
"warlock":"necromancer";"mage",
"abjurer":"mage";"cleric",
 ]);

*/

  subguilds = ([
        "fighters" : "/guilds/fighter/fighter.c",
        "weaponmaster": "/guilds/fighter/weapon_master.c",
        "blademasters" : "/guilds/fighter/blades.c",
        "bludgeonists" : "/guilds/fighter/bludgeons.c",
        "barbarians" : "/guilds/fighter/barbarian.c",
        "warriors" : "/guilds/fighter/warrior.c",
        "veterans" : "/guilds/fighter/veterans.c",
        "body builders" : "/guilds/fighter/body_builders.c",
        "acrobats" : "/guilds/fighter/acrobats.c",
        "smith" : "/guilds/fighter/smith.c",
        "axers" : "/guilds/fighter/axes.c",
        "defenders" : "/guilds/fighter/defender.c",
        "berserkers" : "/guilds/fighter/berserker.c",
        "rangers" : "/guilds/fighter/ranger.c",
                
        "apprentice clerics":"/guilds/channel/appr_cleric.c",
        "adept clerics":"/guilds/channel/adept_cleric.c",
        "high clerics":"/guilds/channel/high_cleric.c",
                
        "abjurer" : "/guilds/abjurer/abjurers.c",
        "masters of sorcery": "/guilds/abjurer/masters_of_sorcery.c",
        "masters of abjuration": "/guilds/abjurer/masters_of_abjuration.c",
        "masters of vulnerability": "/guilds/abjurer/masters_of_vulnerability.c",
        
        "psionicists": "/guilds/psi/psiguild.c",
        "emphatics":"/guilds/psi/caster_psionicists.c",
        "telekinetics": "/guilds/psi/fighter_psionicists.c",
                
        "martial artist": "/guilds/artists/base_guild.c",
        "mind focusers": "/guilds/artists/mind_focusers.c",
        "body focusers": "/guilds/artists/body_focusers.c",
        "path of masters": "/guilds/artists/path_of_masters",
                
        "merchants": "/guilds/mage/merchant.c",
        "navigators": "/guilds/mage/navigator.c",
        "fire school": "/guilds/mage/fire_adept.c",
        "scroll scribblers" : "/guilds/mage/scroll_scribblers.c",
        "illusionists" : "/guilds/mage/illusionists.c",
        "advanced mages" : "/guilds/mage/adv_mages.c",
        "ice school" : "/guilds/mage/ice_adept.c",
        "master mages" : "/guilds/mage/master_mage.c",
        "apprentice mages" : "/guilds/mage/apprmage.c",
        "poison school" : "/guilds/mage/poison_adept.c",
        "arcaners" : "/guilds/mage/arcaners.c",
        "electricity school" : "/guilds/mage/electric_adept.c",
                
        "school of dark power" : "/guilds/necro/dark_power.c",
        "necromancers" : "/guilds/necro/base_guild.c",
        "master animators" : "/guilds/necro/animators.c",
        "apprentice controllers" : "/guilds/necro/control1.c",
        "adept controllers" : "/guilds/necro/control2.c",
        "unholy lords" : "/guilds/necro/unholy_lords.c",
        "necromancer adepts" : "/guilds/necro/necro.c",
                
        "warlocks" : "/guilds/warlock/warlock.c",
        "initiate of chaos" : "/guilds/warlock/warlock2.c",
        "master warlocks" : "/guilds/warlock/warlock3.c",
        "chaos fighters" : "/guilds/warlock/warlock4.c",
        "grand warlocks" : "/guilds/warlock/warlock5.c",
        "chaos masters" : "/guilds/warlock/warlock6.c",

        "paladin" : "/guilds/paladin/baseguild.c",
        "battlemage" : "/guilds/battlemage/baseguild.c",
          ]);
}


