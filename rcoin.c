#include "sqlite3shell.c"    /**assuming "sqlite3.c" is linked

	<Linker>	<Add option="-lpthread -ldl" /></Linker>

    SOURCES += rcoin.c
    SOURCES += sqlite3.c
    QMAKE_LIBS += -lpthread -ldl

	http://forums.codeblocks.org/index.php?topic=9236.0
	http://www.sqlite.org/howtocompile.html
	http://www.sqlite.org/datatype3.html
 */
#include "rcoin.h"         /** including "sqlite3shell.c" and assuming
 "sqlite3.c" is linked*/
/** to ask...  sha256.c is now  linked
 i am using c coding that allow object orientation (such as in
 cc) including sqlight and have this question: What and why
 is your preferred c code library for hash symmetric and
 asymmetric algorithms such as rsa aes256 SHA256 SHA512 etc
 and where can i find good examples of use of such code?
 see ~/Desktop/rcoin/c/gnupg-2.0.21
 http://www.tutonics.com/2012/11/gpg-encryption-guide-part-3-digital.html
hash supported by gpg are: SHA1, SHA256, and SHA512.


*/
/** recomanded c libarry  sha256.c is now  linked
=>      openssl  sha256.c is now  linked
        gnutls
        axtls
 --- https://en.wikipedia.org/wiki/Comparison_of_TLS_Implementations#Code_Size_and_Dependencies
---
 nettle (google)
 blind signature  by david chaum(ian)
 signed encrypted http://en.wikipedia.org/wiki/Blind_signature
======================

//#include <openssl/sha.h> //http://nagareshwar.securityxploded.com/2010/11/23/cryptocode-create-sha256-hash-using-openssl/
//#include <openssl/ssl.h>     // see also Cryptography of Bitcoin by Edward Z.txt
//#include <axtls>
//http://axtls.sourceforge.net/dox/index.html
//https://www.schneier.com/blowfish-download.html
*/
/**??
2.+ Users:?pic or null , so that all users have user table, but only payye can see the one and hence the triplepin is more relabale id, whould this also include used id name email adress etc this is depneded on the community?


??
see also	     http://stackoverflow.com/questions/14244627/get-number-of-days-since-epoch-in-c-cross-platform
	      http://en.wikipedia.org/wiki/C_date_and_time_functions
	      http://en.cppreference.com/w/c/chrono/difftime
	      http://en.wikipedia.org/wiki/Epoch_%28reference_date%29



*/
/**to clean:

** to have 3 level of notification: updates: ,  just geting updates, common: using the passward for respoerty nd log and senceteve: using pasward for wallet sorted by value or all coins by coins type sortedt by id. notification and communication seee https://github.com/cryptocat/cryptocat https://github.com/jafeha/parabird usb lock/encrypt can we get write only once read only usb? is it also for phone? mount the USB drive read-only? wased switched
use case to aply to: as extentantion for the xnottifier plugin of firefox.

each of the buisness in the neiberhood hold table of users, being potentional buyers, (rings.users table), which is indexed by hash(pic(user)), where each user in buying time has the pic to be given to the seller hashing the pic to match the index, only after idenitfieng the pic as of the buyer and aprrovng the payment by signuter and triplepin/passward (as in creadit)! so instead of creadit card, we have pic issused by the ceneter. in addition the center need to produce some machin scaning pic and hashing it. the pci is digitailzed, use has id and access to it by pasward in the database of the seler.

http://stackoverflow.com/questions/800685/which-cryptographic-hash-function-should-i-choose
users-table= hash(16digittriplepin) =>  assymetric_enc_by_payee(pic(payer)),
    from which pic the hash(pic(payer)) is used as  id(payer),
    where the pic is used to verify the payer
    by the payee in the transaction time!
http://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c
//http://xnotifier.tobwithu.com/dp/
//http://en.wikipedia.org/wiki/Digital_signature
***
starting expirmintal using sqilte with its own hash, (which might be not the one we need), where rcoin can be 1 of 3 or 4 demones which only make what is special for rcoin (the other 2 are openssl/ssl.h and sqilte+ communication-such-as-p2p/mail ).

the db and the prgram and rcoin code are dotred iin encrypted driectory (login by passward to encrypt it include also notifying all other memebres, since the db includes log and trsury of the community). this is not when entring the wallet or being notfied and is used as a muser for security providing allarming situation for all themembers when is attacted.
																																											 .
info(coin)<-hash(id(coin)) -> transaction-> hash(transaction)-> owner prove...
inf(coin) is in aditional table/db, so we have 3 tables

as for qulission , in our case if the hash is of the real info, which is restored encritly and sepertl, then in creation we can identify the collution.
this can be also working with sifrat bikoret ....
//   r.sum (int a, int b)    {        return a + b;    }
*/
/**to connect
http://p2pfoundation.net/Complementary_Currency_Software
*/
static rcoin_type r = {    /** our only 1 global! Like a c++ class rcoin.*/
/**c++ members*/
	.Escape  = &rcoin_Escape,/**Destructor*/
	.New     = &rcoin_New, /**Constructor*/
	.member_is_operator='1',
      .man =  (char*[]) {
   "         rcoin - A Coin Of Respect, ...",
   " rcoin  is a credit between members of a community (ring) issuing that coin for the use of its members to stop their Gentrifying. It is TimeLimited coin as the daily constant lost of its value is equally redistributed as a gain between the ring's members. As such It is a social justice measure of evaluation and a medium of exchange, which is not money, nor equivalent to money, for use only between the members of the ring. This enable fighting the globalization locally!",
   "To allow more mobility of such means of exchange, while such rings are bottom up self organized, the rings could be comcomized, so that the holding in each ring is evaluated by coin of respect issued the bigger ring, find more in http://is-with.wikidot.com .",
 "Use case: coffee-shop and bakery are 2 divisions in the ring the ring buy chocolate and give it for coin of respect to the bakery and the bakery, after making from that a cake, give the cake for coins of respect to the coffee-shop and the ring, but not the coffee-shop, sell the cake in money to an outer client and in coinf or respect to the members in the ring.",
 "					.... The Calculus of the Coin:",
 "     CoinAge, starting in zero, is the time in days for all the lifetime of that coin, where in each day CoinAge is increased by 1 as long as CoinAge is smaller than CoinLifetime and where\n\
     MembersCount is the number of members in the community issuing the coin, such that\n\
          CoinValue             = CoinStartValue * (1- CoinAge++/CoinLifetim)\n\
          MemberDividend        = MemberDailyEarning * CoinAge,\
          OwnerDailyLost        = CoinStartValue     / CoinLifetime,\
          MemberDailyEarning    = OwnerDailyLost     / MembersCount\
          and daily CoinValue  -= OwnerDailyLost.\
     The study of change can be represented as the line value of the coin's holder versus the plane value of other members: 	in 	3d and 1 colour, where X = CoinAge, Y = CoinValue and Z = MembersCount or in 2d and 2 colours: of the owner and  of one of the other of memebrs, where X = CoinAge and Y= CoinValue.",
 "					.... About this code:",
 "we use tyedef hierarchy in c to enable c++ features, as the previous (and included) code is the primitve and includable ones and and the last defined element is rcoin_elements type including destructor and constructor and functions and types.",
 "						.... The Network protocol description:",
 "As a digital coin and compared for example with bitcoin, how to secure it ?\
Still in development on rcoin project on github, of which members are to become member owners over is source, where\
\
    The equal (re)distribution in rcoin is used instead of the mining in bitcoin.,\
    The delivering of the coin is by delivering the receipt[n] having the id(coin), where each member has both tables: Repository and Log, but only the coin's owner knows the receipt[n] having the id(coin) having the owner signature, such that\
        receipt[n] = (random[n] signed by coin's owner,Hashed(receipt[n-1] ),\
        Repository-table(all members wallets collection):Hashed(id(coin)) => receipt[n] Asymmetrically encrypted by coin's Owner,\
        Log-table:Hashed(receipt[n]) =>\
\
signed by sender-owner (id(coin),id(receiver-Owner)) 	Wallet 	Repository\
Encrypted 	id(coin) 	id(reciver)\
plan text 	id(reciver) 	id(coin)",
"Notes:\
\
    the minimal amount of items in each table = coins amount + noise,\
    delivering the receipt[n] is done by first making a call to the members to verify whether the transaction in the log has the coin and if yes to change the coin to have the new transacion[n+1] and to create it\
    to hash is of hashing-without-collusion: for (x=0;x<X;x++) Y=SHA256(Y), where X<1 and X is the number of creating hash on the hash until having no hash-collusion, and then X and Y are concatenated with the and X is given as token to the user as additional parameter.",
    "										..... 'printing' coins parmaters...\
The Self adjustment in the ring by 'printing' its coins of respect: The ring creates its coins to projects its (new) Gini, by both:\
\
    A) maintaining its social obligation amounted to Mini guaranteeing minimal amount of coins per each of its members and\
    B) by delivering an additional equal dividend D to each of its members,\
\
such that\
\
    -1 <= min_Injustice <= Gini - Justice <= max_Injustice <= 1 and\
    0 <= min_stress <= Gini / Justice <= max_stress,\
\
where\
\
    Gini is the ratio of the areas on the Lorenz curve diagram used as a measurement for inequality in the ring, as 0<= Gini<=1,\
    X is the number of ring's members,\
    Y is the amount of ring's coins,\
    D is an equal Dividend per ring's member, as D*X is added to Y per each round,\
    A is the Average of coins per ring's member, as A=Y/X,\
    Mini the Minimal amount of coins guaranteed per each of the ring's members,\
    Justice = Mini/A, Justice as in ring's social Justice, as 0<=Justice<=1, since Mini<=A.\
\
Notes:\
\
    The rings 'printing' coins is to be done with specific coins's-lifetime, D and Mini, using limitation such as min_Injustice, max_Injustice, min_stress, or max_Stress to response to specific changes of the Justice and Gini in the ring, for to meet some policy, which are to be made automatically and/or directly under decision made by people.\
    Even when the coin of respect are only in the ring tradable, still the tradability out of that ring is optional by member coin, which is the value of accountability-and-ownership of one member owner, as member coin is measured by coin of respect of other ring, money or money's equivalent.\
\
    Since the db is depdndet on number of coins,\
we will have trasnction for reducing number of coins by exchaning them for smaller number of coin of higher value and back."                  },
/**sql members:*/
	.Err     = NULL,
	.My_db   = NULL,
	.Op_db   = NULL,
	.sql     =  &rcoin_sql,
	.open    =  &rcoin_open,
/**calculus members*/
    .calc    = { //.TodayDate,//=(((time_t)time(NULL)) / 86400),
/**in .new:
r.calc.TodayDate= time(NULL)/ 86400;
if (r.calc.LastCalculatedDate<r.calc.TodayDate){}else{}
*/
                 //.info = NULL,/** { .StartValue=0, .Id=0, .Lifetime=0, .LastDate=0,},*/
                 .CoinValue =&rcoin_CoinValue,
                 .MemberDividend=&rcoin_MemberDividend,
               },
};// r object of rcoin_type is intiailized
/***/
int rcoin_New(void){       /** r.new as a C++ Constructor*/
     r.calc.TodayDate= time(NULL)/ 86400;//???
r.calc.MembersAmount=1;///??
    if (r.calc.LastCalculatedDate<r.calc.TodayDate){}else{}

	if(!r.open()) return(0);
	//fprintf(stdout, "Opened database and intitate tables successfully\n");
    fprintf(stdout,"%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n%s",
         r.man[0],r.man[1],r.man[2],r.man[3],
         r.man[4],r.man[5],r.man[6],r.man[7],
         r.man[8],r.man[9],r.man[10],r.man[11]  );
 return(1);
}
int rcoin_Escape(void){    /** r.Escape as a C++ Destructor*/
	return(sqlite3_close(r.My_db));
}
/***/
int rcoin_sql(char *sql){  /** r.sql Executing SQL statement*/
 if( ( sqlite3_exec(r.My_db, sql, callback, 0, &r.Err)) == SQLITE_OK ) return (0);
 fprintf(stderr, "SQL error: %s\r\n", r.Err);
 fprintf(stdout,"SQL statment: %s\r\n", sql);
 sqlite3_free(r.Err);
 return(1);
}//http://zetcode.com/db/sqlite/datamanipulation/

int rcoin_open(void){/** r.open Opening 4 db in the encrypted directry includng this app and intiating its tables.*/
 if( !sqlite3_open("PrivatelyCoins.rcoin.db", &r.My_db) ){/**se[member]PrivatelyCoins-db (of any coin in Treasury and in others of members'coin)*/
     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(r.My_db));
     return(0);}
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Treasury'(" "id INTEGER PRIMARY KEY NOT NULL," "coin BLOB(16) NOT NULL);")) return(0);/**Treasury:{id(coin)=>coin}  <-of any-other, for adding value by.MemberDividend)*/
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Treasur'(" "id INTEGER PRIMARY KEY NOT NULL," "coin BLOB(16) NOT NULL);")) return(0);/**Treasur:{id(coin)=>coin}  <-of the-member, for reducing value by .CoinValue)*/
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Wallet'(" "CoinValue INTEGER PRIMARY KEY NOT NULL," "coin BLOB(16) NOT NULL);"))

/**to change the tables see rcoin.h*/
  return(0);/**Wallet:{CoinValue=>coin} <-of the-member, daily updated)*/
 if( !sqlite3_open("PrivatelyWho.rcoin.db", &r.My_db) ){/**se[member]PrivatelyWho-db ---(of self and her/his customers)*/
     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(r.My_db));
     return(0);}
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Self'(" "IdPic INTEGER PRIMARY KEY NOT NULL," "Pic BLOB NOT NULL);")) return(0);/**Self{id(pic)=> pic}<-of the-member,id(user)== hash(pic,triplepin,id(pic)))*/
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Payers'(" "hash_12digit_triplepin CHAR(512) PRIMARY KEY NOT NULL," "Pic BLOB NOT NULL);")) return(0);/**Payers:ae[member]{hash(12digittriplepin)=>pic} <-of those who pay to the member )*/
 if(!r.member_is_operator) return (1);/**that is it! next is only for member acting as operator*/
 if(! sqlite3_open("CommonlyCoin.rcoin.db", &r.My_db) ){/**se[member]CommonlyCoin-db: (of-any coin)*/
     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(r.My_db));
     return(0);}
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Proves'(" "id_coin_Hashed CHAR(512) PRIMARY KEY NOT NULL," "receipt_Asymmetrically_encrypted_by_Owner_of_coin CHAR(512) NOT NULL);" )) return(0);
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Transactions'(" "receipt_Hashed CHAR(512) PRIMARY KEY NOT NULL," "signed_by_sender_owner_id_coin__id_receiver_Owner CHAR(512) NOT NULL);")) return(0);
 if(! sqlite3_open("CommonlyWho.rcoin.db", &r.My_db) ){/**se[member]CommonlyWho-db: (of-any member)*/
     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(r.My_db));
     return(0);}
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Users'(" "Hash_id_member CHAR(512) PRIMARY KEY NOT NULL," "triplepin_and_signed_by_sender_owner_rand BLOB NOT NULL);")) return(0);/**Users:    ae[member]{hash(id(member))=>triplepin,ae[Owner](rand[n],hash(rand[n-1]))}*/
    if(r.sql("CREATE TABLE IF NOT EXISTS 'Profiles'(" "Hash_rand CHAR(512) PRIMARY KEY NOT NULL," "usr_info_partly_encrypted BLOB NOT NULL);")) return(0);/** Profiles:ae[member]{hash(rand[n]) => info( user, patrly ae[user])}*/
 return (1);
}//http://www.sqlite.org/c_interface.html#callback_returns_nonzero
/***/
float rcoin_CoinValue (coin_info_type *coin){/**on Treasur the coin's values to be reduced:
the major (v/1024) and minor (v*1024) values, when implemented on the coins of the member in Treasur.*/

return(coin->StartValue-((coin->StartValue *(r.calc.TodayDate+coin->Lifetime-coin->LastDate))/coin->Lifetime));}
float rcoin_MemberDividend(coin_info_type *coin){/**on Treasury the coin's values to be added:
the major (v/1024) and minor (v*1024) values, when implemented on the coins of the others in the Treasury.*/
 return ((coin->StartValue*(r.calc.TodayDate+coin->Lifetime-coin->LastDate)) /(r.calc.MembersAmount*coin->Lifetime));}
/***/
int main(int argc, char* argv[]){


    fprintf(stdout,"%s%u",argv[0],argc);
	if(!r.New()) exit(0);
 return  (r.Escape());
}

