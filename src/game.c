#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define PLAYER_NUMBER_MAX 6
#define CARD_NUMBER_MAX 54
#define GAME_INFO SetCards* deck, SetCards hands[PLAYER_NUMBER_MAX], SetCards* play_cards, unsigned int* turn_player, unsigned int* last_player
#define game_info deck, hands, play_cards, turn_player, last_player
#define game_infoex &deck, hands, &play_cards, &turn_player, &last_player

enum Bool;
enum CordKind;

struct Card;
struct SetCards;

typedef enum Bool Bool;
typedef enum CordKind CordKind;
typedef struct Card Card;
typedef struct SetCards SetCards;

enum Bool
{
    false,
    true,
};

enum CordKind
{
    NonCard  = 0x0000,

    Color    = 0x0f00,
    Suit     = 0x00f0,
    Number   = 0x000f,

    Black    = 0x0100,
    Red      = 0x0200,

    Spade    = 0x0010,
    Club     = 0x0020,
    Diamond  = 0x0030,
    Heart    = 0x0040,

    One      = 0x0001,
    Two      = 0x0002,
    Three    = 0x0003,
    Four     = 0x0004,
    Five     = 0x0005,
    Six      = 0x0006,
    Seven    = 0x0007,
    Eight    = 0x0008,
    Nine     = 0x0009,
    Ten      = 0x000a,
    Eleven   = 0x000b,
    Twelve   = 0x000c,
    Thirteen = 0x000d,
    Ace      = One,
    Jack     = Eleven,
    Queen    = Twelve,
    King     = Thirteen,
    Joker    = 0x1000,

    SpadeOne      = Black | Spade | One,
    SpadeTwo      = Black | Spade | Two,
    SpadeThree    = Black | Spade | Three,
    SpadeFour     = Black | Spade | Four,
    SpadeFive     = Black | Spade | Five,
    SpadeSix      = Black | Spade | Six,
    SpadeSeven    = Black | Spade | Seven,
    SpadeEight    = Black | Spade | Eight,
    SpadeNine     = Black | Spade | Nine,
    SpadeTen      = Black | Spade | Ten,
    SpadeEleven   = Black | Spade | Eleven,
    SpadeTwelve   = Black | Spade | Twelve,
    SpadeThirteen = Black | Spade | Thirteen,
    SpadeAce      = Black | Spade | Ace,
    SpadeJack     = Black | Spade | Jack,
    SpadeQueen    = Black | Spade | Queen,
    SpadeKing     = Black | Spade | King,

    ClubOne      = Black | Club | One,
    ClubTwo      = Black | Club | Two,
    ClubThree    = Black | Club | Three,
    ClubFour     = Black | Club | Four,
    ClubFive     = Black | Club | Five,
    ClubSix      = Black | Club | Six,
    ClubSeven    = Black | Club | Seven,
    ClubEight    = Black | Club | Eight,
    ClubNine     = Black | Club | Nine,
    ClubTen      = Black | Club | Ten,
    ClubEleven   = Black | Club | Eleven,
    ClubTwelve   = Black | Club | Twelve,
    ClubThirteen = Black | Club | Thirteen,
    ClubAce      = Black | Club | Ace,
    ClubJack     = Black | Club | Jack,
    ClubQueen    = Black | Club | Queen,
    ClubKing     = Black | Club | King,

    DiamondOne      = Red | Diamond | One,
    DiamondTwo      = Red | Diamond | Two,
    DiamondThree    = Red | Diamond | Three,
    DiamondFour     = Red | Diamond | Four,
    DiamondFive     = Red | Diamond | Five,
    DiamondSix      = Red | Diamond | Six,
    DiamondSeven    = Red | Diamond | Seven,
    DiamondEight    = Red | Diamond | Eight,
    DiamondNine     = Red | Diamond | Nine,
    DiamondTen      = Red | Diamond | Ten,
    DiamondEleven   = Red | Diamond | Eleven,
    DiamondTwelve   = Red | Diamond | Twelve,
    DiamondThirteen = Red | Diamond | Thirteen,
    DiamondAce      = Red | Diamond | Ace,
    DiamondJack     = Red | Diamond | Jack,
    DiamondQueen    = Red | Diamond | Queen,
    DiamondKing     = Red | Diamond | King,

    HeartOne      = Red | Heart | One,
    HeartTwo      = Red | Heart | Two,
    HeartThree    = Red | Heart | Three,
    HeartFour     = Red | Heart | Four,
    HeartFive     = Red | Heart | Five,
    HeartSix      = Red | Heart | Six,
    HeartSeven    = Red | Heart | Seven,
    HeartEight    = Red | Heart | Eight,
    HeartNine     = Red | Heart | Nine,
    HeartTen      = Red | Heart | Ten,
    HeartEleven   = Red | Heart | Eleven,
    HeartTwelve   = Red | Heart | Twelve,
    HeartThirteen = Red | Heart | Thirteen,
    HeartAce      = Red | Heart | Ace,
    HeartJack     = Red | Heart | Jack,
    HeartQueen    = Red | Heart | Queen,
    HeartKing     = Red | Heart | King,

    RedJoker   = Red   | Joker,
    BlackJoker = Black | Joker,
};

struct Card{
    CordKind ck;
};

struct SetCards
{
    Card list[CARD_NUMBER_MAX];
};

unsigned int player = 0;
unsigned int player_number = 4;
const SetCards AllCards = {
    SpadeAce,   SpadeTwo,   SpadeThree,   SpadeFour,   SpadeFive,   SpadeSix,   SpadeSeven,   SpadeEight,   SpadeNine,   SpadeTen,   SpadeJack,   SpadeQueen,   SpadeKing,
    ClubAce,    ClubTwo,    ClubThree,    ClubFour,    ClubFive,    ClubSix,    ClubSeven,    ClubEight,    ClubNine,    ClubTen,    ClubJack,    ClubQueen,    ClubKing,
    DiamondAce, DiamondTwo, DiamondThree, DiamondFour, DiamondFive, DiamondSix, DiamondSeven, DiamondEight, DiamondNine, DiamondTen, DiamondJack, DiamondQueen, DiamondKing,
    HeartAce,   HeartTwo,   HeartThree,   HeartFour,   HeartFive,   HeartSix,   HeartSeven,   HeartEight,   HeartNine,   HeartTen,   HeartJack,   HeartQueen,   HeartKing,
    RedJoker,   BlackJoker,
};

void InsertCards(SetCards* set, Card card, unsigned int place);
void ShuffleCards(SetCards* set);
void OutputCard(Card* card);
void OutputCards(SetCards* set);
void SortCards(SetCards* set);
void NextTurn(GAME_INFO);
Bool IsStrongCards(Card target, Card base, GAME_INFO);
Bool IsPairCards(SetCards* set);
Bool CanPlayCards(GAME_INFO);
Bool PlayCards(GAME_INFO);
void ChoiceAction(GAME_INFO);
void OneGame();
unsigned int NumberCards(SetCards* set);
unsigned int PlaceCard(SetCards* set, Card card);
Bool HaveCard(SetCards* set, Card card);
Card ExtractionCards(SetCards* set, unsigned int place);

// カードの集合に任意のカードを挿入する
void InsertCards(SetCards* s, Card c, unsigned int p)
{
    unsigned int place;

    if(c.ck == NonCard){
        return;
    }

    for(place = 0 ; place < p && s->list[place].ck != NonCard && place < CARD_NUMBER_MAX ; place++);

    if(place < CARD_NUMBER_MAX){
        for(unsigned int i = CARD_NUMBER_MAX - 1 ; i > place ; i--){
            s->list[i].ck = s->list[i-1].ck;
        }

        s->list[place].ck = c.ck;
    }
}

// カードの集合をシャッフルする
void ShuffleCards(SetCards* s)
{
    for(unsigned int i = 0, r = rand()%(CARD_NUMBER_MAX - 1) ; i < CARD_NUMBER_MAX ; i++, r = rand()%(CARD_NUMBER_MAX - 1)){
        if(r >= i){
            r++;
        }

        s->list[i].ck ^= s->list[r].ck ^= s->list[i].ck ^= s->list[r].ck;
    }
}

// カードを出力する
void OutputCard(Card* c)
{

    if((c->ck & Joker) != 0){
        switch(c->ck & Color){
            case Black:
                printf("BJoker");
                break;
            case Red:
                printf("RJoker");
                break;
        }
    }else{
        switch(c->ck & Suit){
            case Spade:
                printf("S");
                break;
            case Club:
                printf("C");
                break;
            case Diamond:
                printf("D");
                break;
            case Heart:
                printf("H");
                break;
        }
        switch(c->ck & Number){
            case Ace:
                printf("A");
                break;
            case Two:
                printf("2");
                break;
            case Three:
                printf("3");
                break;
            case Four:
                printf("4");
                break;
            case Five:
                printf("5");
                break;
            case Six:
                printf("6");
                break;
            case Seven:
                printf("7");
                break;
            case Eight:
                printf("8");
                break;
            case Nine:
                printf("9");
                break;
            case Ten:
                printf("10");
                break;
            case Jack:
                printf("J");
                break;
            case Queen:
                printf("Q");
                break;
            case King:
                printf("K");
                break;
        }
    }
}

// カードの集合を出力する
void OutputCards(SetCards* s)
{
    Card c = {0};
    char p[3] = "";

    printf("[");

    for(unsigned int i = 0 ; (c.ck = s->list[i].ck) != NonCard && i < CARD_NUMBER_MAX ; i++){
        printf(p);

        OutputCard(&(s->list[i]));

        p[0] = ',';
        p[1] = ' ';
    }

    printf("]\n");
}

// カードの集合をソートする
void SortCards(SetCards* s)
{
    unsigned int number = NumberCards(s);

    for(unsigned int i = 0 ; i < CARD_NUMBER_MAX && s->list[i].ck != NonCard ; i++){
        for(unsigned int j = i + 1 ; j < CARD_NUMBER_MAX && s->list[j].ck != NonCard ; j++){
            if(s->list[i].ck > s->list[j].ck){
                s->list[i].ck ^= s->list[j].ck ^= s->list[i].ck ^= s->list[j].ck;
            }
        }
    }
}

// 次のターンプレイヤーに移す
void NextTurn(GAME_INFO)
{
    // 次のターンプレイヤーに移行(次のプレイヤーのカードが残っているかは考慮しない)
    (*turn_player)++;
    if((*turn_player) >= PLAYER_NUMBER_MAX){
        (*turn_player) = 0;
    }

    // カードが残っているプレイヤーまでターンプレイヤーを移し続ける
    while(hands[(*turn_player)].list[0].ck == NonCard){
        // 最後にカードをプレイしたプレイヤーまでターンが回ったら場のカードを流す
        if((*turn_player) == (*last_player)){
            printf("  Board deleted\n");
            while(deck->list[0].ck != NonCard){
                ExtractionCards(deck, 0);
            }

            (*last_player) = PLAYER_NUMBER_MAX;
        }

        // 次のターンプレイヤーに移行(次のプレイヤーのカードが残っているかは考慮しない)
        (*turn_player)++;
        if((*turn_player) >= PLAYER_NUMBER_MAX){
            (*turn_player) = 0;
        }
    }

    // 最後にカードをプレイしたプレイヤーまでターンが回ったら場のカードを流す
    if((*turn_player) == (*last_player)){
        printf("  Board deleted\n");
        while(deck->list[0].ck != NonCard){
            ExtractionCards(deck, 0);
        }

        (*last_player) = PLAYER_NUMBER_MAX;
    }
}

// tがbより強ければtrueを返す
Bool IsStrongCards(Card t, Card b, GAME_INFO)
{
    // カードの強さ順
    SetCards rank[13] = {Two, Ace, King, Queen, Jack, Ten, Nine, Eight, Seven, Six, Five, Four, Three};

    // bがジョーカー
    if((b.ck & Joker) != 0){
        return false;
    }

    if((t.ck & Joker) != 0){
        return true;
    }

    t.ck &= Number;
    b.ck &= Number;

    if(PlaceCard(rank, t) < PlaceCard(rank, b)){
        return true;
    }

    return false;
}

// プレイするカードが一枚かペアのときにtrueを返す
Bool IsPairCards(SetCards* s)
{
    Card rank;

    // 一枚もないならペアじゃない
    if(s->list[0].ck == NonCard){
        return false;
    }

    // 1枚目カードの数を記録(ジョーカーは0になる)
    rank.ck = s->list[0].ck & Number;

    // 1枚目以外のカードの数を確認
    for(unsigned int i = 1 ; s->list[i].ck != NonCard ; i++){
        // 同じ数かジョーカーでなければペアではない
        if((rank.ck != (s->list[i].ck & Number)) && ((s->list[i].ck & Joker) == 0)){
            return false;
        }
    }

    return true;
}

// play_cardsがプレイできるならtrueを返す
Bool CanPlayCards(GAME_INFO)
{
    // ペアのとき
    if(IsPairCards(play_cards) == true){
        // 場にカードがなければ出せる
        if(deck->list[0].ck == NonCard){
            return true;
        }

        // 場のカードとプレイするカードの枚数が異なれば出せない
        if(NumberCards(deck) != NumberCards(play_cards)){
            return false;
        }

        // 場のカードがペアでなければ出せない
        if(IsPairCards(deck) == false){
            return false;
        }

        // 場のカードよりプレイするカードが強くなければ出せない
        if(IsStrongCards(play_cards->list[0], deck->list[0], game_info) == false){
            return false;
        }

        return true;
    }

    return false;
}

// play_cardsのプレイを試みる
Bool PlayCards(GAME_INFO)
{
    // play_cardsにカードがなければプレイできない
    if(play_cards->list[0].ck == NonCard){
        printf("  Cannot play!\n");
        return false;
    }

    // プレイできないカードならもちろんプレイできない
    if(CanPlayCards(game_info) == false){
        printf("  Cannot play!\n");
        return false;
    }

    // deckのカードを削除する
    while(deck->list[0].ck != NonCard){
        ExtractionCards(deck, 0);
    }

    // プレイするカードをdeckに追加し、ターンプレイヤーの手札から削除する
    while(play_cards->list[0].ck != NonCard){
        InsertCards(deck, play_cards->list[0], CARD_NUMBER_MAX);
        ExtractionCards(&(hands[*turn_player]), PlaceCard(&(hands[*turn_player]), ExtractionCards(play_cards, 0)));
    }

    // 場に出した最後のプレイヤーを記録
    (*last_player) = (*turn_player);

    return true;
}

// ターンプレイヤーの行動を選択する
void ChoiceAction(GAME_INFO)
{
    Card card = {0};
    char buffer[256];

    // プレイヤーの番号の表示
    printf("Player%d\n", *turn_player);
    SortCards(&(hands[*turn_player]));

    // play_cardsの中身を全部削除
    while(play_cards->list[0].ck != NonCard){
        ExtractionCards(play_cards, 0);
    }

    while(1){
        // 入力部とその前に出す表示
        if(deck->list[0].ck != NonCard){
            printf("  board");
            OutputCards(deck);
        }
        printf("  hand");
        OutputCards(&(hands[*turn_player]));
        if(play_cards->list[0].ck != NonCard){
            printf("  play");
            OutputCards(play_cards);
        }
        printf("  Input action\n   >> ");
        fgets(buffer, sizeof(buffer), stdin);

        // すべての大文字を小文字に変更
        for(unsigned int i = 0 ; i < sizeof(buffer) ; i++){
            buffer[i] = tolower(buffer[i]);

            if(buffer[i] == '\n'){
                buffer[i] = '\0';
            }
        }

        // パスをする
        if(strcmp(buffer, "pass") == 0){
            return;
        }

        // ゲームを強制終了
        else if(strcmp(buffer, "exit") == 0){
            exit(0);
        }

        // カードをプレイする
        else if(strcmp(buffer, "play") == 0){
            if(PlayCards(game_info) == true){
                return;
            }
        }

        // どれにも当てはまらないときにカード選択
        else{
            // 黒色のジョーカーを選択
            if(strcmp(buffer, "bjoker") == 0){
                card.ck = BlackJoker;
            }

            // 赤色のジョーカーを選択
            else if(strcmp(buffer, "rjoker") == 0){
                card.ck = RedJoker;
            }

            // ジョーカー以外を選択
            else{
                // スートの読み込み
                switch(buffer[0]){
                    case 's':
                        card.ck = Spade | Black;
                        break;
                    case 'c':
                        card.ck = Club | Black;
                        break;
                    case 'd':
                        card.ck = Diamond | Red;
                        break;
                    case 'h':
                        card.ck = Heart | Red;
                        break;
                }

                // 数の読み込み
                switch(buffer[1]){
                    case 'a':
                        if(buffer[2] == '\0'){
                            card.ck |= Ace;
                        }
                        break;
                    case '1':
                        if(buffer[2] == '\0'){
                            card.ck |= One;
                        }else{
                            switch(buffer[2]){
                                case '0':
                                    if(buffer[3] == '\0'){
                                        card.ck |= Ten;
                                    }
                                    break;
                                case '1':
                                    if(buffer[3] == '\0'){
                                        card.ck |= Eleven;
                                    }
                                    break;
                                case '2':
                                    if(buffer[3] == '\0'){
                                        card.ck |= Twelve;
                                    }
                                    break;
                                case '3':
                                    if(buffer[3] == '\0'){
                                        card.ck |= Thirteen;
                                    }
                                    break;
                            }
                        }
                        break;
                    case '2':
                        if(buffer[2] == '\0'){
                            card.ck |= Two;
                        }
                        break;
                    case '3':
                        if(buffer[2] == '\0'){
                            card.ck |= Three;
                        }
                        break;
                    case '4':
                        if(buffer[2] == '\0'){
                            card.ck |= Four;
                        }
                        break;
                    case '5':
                        if(buffer[2] == '\0'){
                            card.ck |= Five;
                        }
                        break;
                    case '6':
                        if(buffer[2] == '\0'){
                            card.ck |= Six;
                        }
                        break;
                    case '7':
                        if(buffer[2] == '\0'){
                            card.ck |= Seven;
                        }
                        break;
                    case '8':
                        if(buffer[2] == '\0'){
                            card.ck |= Eight;
                        }
                        break;
                    case '9':
                        if(buffer[2] == '\0'){
                            card.ck |= Nine;
                        }
                        break;
                    case 'x':
                        if(buffer[2] == '\0'){
                            card.ck |= Ten;
                        }
                        break;
                    case 'j':
                        if(buffer[2] == '\0'){
                            card.ck |= Jack;
                        }
                        break;
                    case 'q':
                        if(buffer[2] == '\0'){
                            card.ck |= Queen;
                        }
                        break;
                    case 'k':
                        if(buffer[2] == '\0'){
                            card.ck |= King;
                        }
                        break;
                }

                // 存在しないカード情報なら消す
                if((card.ck & Suit) == 0 || (card.ck & Number) == 0){
                    card.ck = NonCard;
                }
            }

            // もし持っていないカードなら選択を取り消し
            if(HaveCard(&(hands[*turn_player]), card) == false){
                card.ck = NonCard;
            }

            // play_cardsに存在しないなら追加
            if(HaveCard(play_cards, card) == false){
                InsertCards(play_cards, card, CARD_NUMBER_MAX);
                SortCards(play_cards);
            }

            // play_cardsに存在するなら削除
            else{
                ExtractionCards(play_cards, PlaceCard(play_cards, card));
            }
        }
    }
}

// 1ゲーム行う
void OneGame()
{
    // deckはゲーム開始時には山札、ゲーム中は場のカードとして扱う
    SetCards deck = {0};
    // プレイヤーごとの手札を管理
    SetCards hands[PLAYER_NUMBER_MAX] = {0};
    // ターンプレイヤーが出すカード
    SetCards play_cards = {0};
    unsigned int remainplayer_number;
    // ターンプレイヤーの番号
    unsigned int turn_player = 0;
    // 最後にカードをプレイしたプレイヤーの番号
    unsigned int last_player = PLAYER_NUMBER_MAX;

    // 山札を生成
    for(unsigned int i = 0 ; i < CARD_NUMBER_MAX ; i++){
        InsertCards(&deck, AllCards.list[i], CARD_NUMBER_MAX);
    }

    // 山札をシャッフルする
    ShuffleCards(&deck);

    // 山札をプレイヤーに配る
    while(deck.list[0].ck != NonCard){
        for(unsigned int i = 0 ; i < player_number ; i++){
            InsertCards(&(hands[i]), ExtractionCards(&deck, 0), CARD_NUMBER_MAX);
        }
    }

    while(1){
        // 残ったプレイヤーをカウント
        remainplayer_number = 0;
        for(unsigned int i = 0 ; i < PLAYER_NUMBER_MAX ; i++){
            if(hands[i].list[0].ck != NonCard){
                remainplayer_number += 1;
            }
        }

        // プレイヤーが残り一人以下でゲーム終了
        if(remainplayer_number <= 1){
            printf("finish\n");
            return;
        }

        // ターンプレイヤーの行動
        ChoiceAction(game_infoex);
        // 次のターンプレイヤーに移動
        NextTurn(game_infoex);
    }
}

// カードの集合の要素数を求める
unsigned int NumberCards(SetCards* s)
{
    // 最初のカードがない要素を探す(カードがない要素番目が最後尾のため)
    for(unsigned int i = 0 ; i < CARD_NUMBER_MAX ; i++){
        // カードがない要素番目を返す
        if(s->list[i].ck == NonCard){
            return i;
        }
    }

    // 最後までカードがあるときカードの最大数を返す
    return CARD_NUMBER_MAX;
}

// カードの集合の任意のカードの要素番目を返す
unsigned int PlaceCard(SetCards* s, Card c)
{
    // cのカードをsから探す
    for(unsigned int i = 0 ; i < CARD_NUMBER_MAX && s->list[i].ck != NonCard ; i++){
        // cのカードがあったとき要素番目を返す
        if(s->list[i].ck == c.ck){
            return i;
        }
    }

    // 見つからないときはカードの最大数を代わりに返す
    return CARD_NUMBER_MAX;
}

// カードの集合に任意のカードが存在すればtrueを返す
Bool HaveCard(SetCards* s, Card c)
{
    return PlaceCard(s, c) == CARD_NUMBER_MAX ? false : true;
}

// カードの集合から要素番目のカードを抽出する
Card ExtractionCards(SetCards* s, unsigned int p)
{
    Card c = {NonCard};

    // pがカードの最大数未満のとき動く
    if(p < CARD_NUMBER_MAX){
        if(s->list[p].ck != NonCard){
            // p番目のカードを抽出
            c.ck = s->list[p].ck;

            // p番目以降を前に詰める
            for(unsigned int i = p ; i < CARD_NUMBER_MAX - 1 ; i++){
                s->list[i].ck = s->list[i+1].ck;
            }

            // 最後の要素をカード無しにする
            s->list[CARD_NUMBER_MAX-1].ck = NonCard;
        }
    }

    return c;
}

int main()
{
    SetCards hand = {0};

    srand((unsigned)time(NULL));

    OneGame();

    return 0;
}
