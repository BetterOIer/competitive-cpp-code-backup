//*** Le vent se lève, il faut tenter de vivre !***
/*
Why Kiki's Delivery Service Is The Perfect Coming of Age Story
Studio Ghibli is well known for producing timeless classics that have engaging protagonists and enchanting storylines. Spirited Away, Castle in the Sky and My Neighbor Totoro are all examples of movies that have captured hearts in both the East and West. And now that the Ghibli catalog is hitting streaming services for the first time, old and new fans alike are diving back into these worlds of cozy fantasy. Kiki's Delivery Service, released in 1989, is no different. Based on the lesser-known book of the same name by Eiko Kadono, the movie focuses on a 13-year old witch named Kiki who, per ancient traditions, must leave home for a year to make a living in a different town.
Though Kiki is a witch, this isn't your typical magical girl anime where she can use her magic to turn her problems into lollipops and rainbows. Kiki has to fight through various personal and external obstacles to make a life for herself. Like many of Miyazaki's female protagonists, Kiki is a multifaceted character with an endearing tenacity and she makes it easy for us to understand the rollercoaster of emotions she rides as she grows and matures through the movie
With Miyazaki's masterful direction and Studio Ghibli's impeccable execution, Kiki's Delivery Service is a beautiful coming of age story that captures the trials and tribulations of growing up with its charming characters, an intriguing premise and realistic conflicts. For those in need of some nourishing entertainment during these uncertain times, there's no better film to watch right now.
WRITE FOR US! 
Do You Have Proven Online Publishing Experience? Click HERE And Join Our Team!
The movie's core concept is about gaining financial independence from one's parents and that's a key part of growing up. Kiki leaves home at 13, an age people consider to be the threshold into the teen years, and sets out to make her fortune with inspiring optimism. Kiki knows full well that she has to find a job and though she is determined as anybody to start her search, like any aspiring graduate, she finds herself smacked across the face with reality: The beautiful oceanside town is filled with indifferent people, a police officer tries to detain her for flying on her broom and she needs an ID to stay at a hotel.
As a gorgeous sunset paints the sky, Kiki is still very much alone and we start worrying that she hasn't found a place to stay. Anybody having trouble with finding a job recognizes how discouraged and stressed Kiki must be in a world indifferent to her struggles. Thankfully this is a G-rated movie so Kiki quickly finds a job at a bakery with a friendly couple (Osono and Fukuo) but her troubles aren't over. After a cute shopping scene, she finds out how quickly her money runs out, which forces her to get back to setting up her business. But in one day she has a job, a rent-free room and networking connections without needing LinkedIn or Indeed.
Even after Kiki has "made it" with a freelance gig with decent perks from Osono, she has to face another hurdle -- fitting in with her peers. This is exacerbated by her status as the only witch in town and having to wear a black dress she labels boring. Whenever Kiki has a run-in with her friend Tombo's gang, and other girls her age, we can see her put her head down and plow forward with closed body language. Kiki is perfectly sociable with people older than her but it seems that she has some social anxiety when it comes to other girls her age.
RELATED:
Why Kiki's Delivery Service Is Still One Of Miyazaki's Best Films
Part of growing up, particularly but not limited to the adolescent phase, includes wanting to fit in with others as a way to understand one's identity. Kiki has friends back home but in this new city and a new school filled with older kids, she has to start from scratch. Additionally, children make friends with unconscious ease, bonding over things as inane as eating mud pies, yet when people grow up, these activities are frowned upon and they have to find new ways to socialize with their peers.
Kiki lacks any shared experiences with these town girls as a witch and it's sad to see this bubbly character feel so awkward around Tombo's friends. It's not hard to understand why she feels this way as one of Tombo's friends spoke to Kiki quite rudely after a rough delivery in the rain. Kiki's hurt reaction and later brooding is a direct parallel to adolescents who have become self-conscious and are extremely sensitive to their peers' opinions.
Self-doubt is the natural evolution of self-consciousness and Kiki (and young adults in general) have this in spades. After lashing out at Tombo, we see her retreat into a sullen shell and she admits to Jiji (her familiar) that she thinks there's something wrong with her. It's possible the other girls made her feel inferior and Kiki begins to question herself and tries to understand her maelstrom of emotions.
Right after, and in quick succession, Kiki can no longer talk to Jiji and she loses her ability to fly. Losing these powers throws her into a deep depression. She admits to Osono that she feels like she's lost everything. Metaphorically speaking, Kiki's loss speaks to the deeper insecurities she harbors about her identity as a witch and how her self-doubt stops her from finding her true potential. Enter Ursula, a quirky artist who bears no resemblance to a certain purple sea witch, who brings Kiki on a much-needed vacation.
During this trip, Ursula tells Kiki that she may have artist's block and suggests that she take a mental health break. Ursula's advice is very relevant as artist's block is partially caused by self-doubt and a mental break allows Kiki to realize that there's more to herself than just being a witch. But after a deep talk with Ursula about trying to understand one's passions, Kiki begins to find her inner strength as the older woman urges her to think about why she loves flying. Ursula's message is an important one to anyone else struggling with this kind of anxiety. She advises Kiki to counteract the negativity by rediscovering her purpose in life and understanding her passions.
Like any coming of age story, Kiki's Delivery Service culminates in the loss of innocence as a part of growing up. Kiki loses her mother's broom, her flying for a while and, in the Japanese dub, is never able to talk to Jiji again. The symbolism is clear. Kiki cannot unconditionally rely on her parents anymore; she has to consciously learn how to fly and cannot talk to Jiji anymore because she has lost the magic of childhood.
RELATED:
Hayao Miyazaki Has No Idea What A 'Streaming Service' Is
While these all may seem like negatives, they truly aren't because Kiki has gained much more on her journey of self-realization. Kiki has gained independence through taming her own broom and she has become a well-rounded person who is more conscious of her gifts. By losing her flying and fighting to get it back, Kiki realizes how much she loves to fly and she understands her skill on a deeper level. Not being able to talk to Jiji (a possible allegory for an imaginary friend) forced her to come out of her shell and to create a new network of friends and surrogate family.
As we can see from Kiki's struggles, growing up is a painful process but with adulthood comes wisdom, authentic connections and, most importantly, independence. This is the beauty of Kiki's Delivery Service: a bittersweet tale that does a remarkable job of showing a child's inner life while she transitions to adolescence. Hayao Miyazaki once again proves his mastery with spinning stories about childhood and Kiki's Delivery Service is one of the best coming of age movies out there.
*/
#include<iostream>
#include<algorithm>
#define lson (x << 1)
#define rson (x << 1 | 1)
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct LINE{
    long long l;
    long long r;
    long long h;
    int mark;
    bool operator < (const LINE &rhs) const {
		return h < rhs.h;
	}
}line[1000006<<1];
int n;
long long X[1000006<<1],xu,xd,yu,yd;
struct SegTree{
	int l, r, sum;
	long long len;
}tree[1000006<<1];
void pushup(int x){
	int l = tree[x].l, r = tree[x].r;
	if(tree[x].sum)tree[x].len = X[r + 1] - X[l];      
	else tree[x].len = tree[lson].len + tree[rson].len;
}
void build_tree(int x, int l, int r){
    tree[x].l = l, tree[x].r = r;
	tree[x].len = 0;
	tree[x].sum = 0;
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	build_tree(lson, l, mid);
	build_tree(rson, mid + 1, r);
	return;
}
void edit_tree(int x, long long L, long long R, int c) {
	int l = tree[x].l, r = tree[x].r;
	if(X[r + 1] <= L || R <= X[l]) return;
	if(L <= X[l] && X[r + 1] <= R) {
		tree[x].sum += c;
		return pushup(x);
	}
	edit_tree(lson, L, R, c);
	edit_tree(rson, L, R, c);
	pushup(x);
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        xu=read(),yu=read(),xd=read(),yd=read();
        X[(i<<1) - 1] = xu, X[(i<<1)] = xd;
        line[(i<<1)-1] = (LINE){xu, xd, yu, 1},line[(i<<1)] = (LINE){xu, xd, yd, -1};
    }
    n <<= 1;
    sort(line+1, line+n+1);
	sort(X + 1, X + n + 1);
    int tot = unique(X + 1, X + n + 1)-X-1;
    build_tree(1, 1, tot - 1);
    long long ans = 0;
	for(int i = 1; i < n; i++) {
		edit_tree(1, line[i].l, line[i].r, line[i].mark);
		ans += tree[1].len * (line[i + 1].h - line[i].h);
	}
	printf("%lld", ans);
	return 0;
}