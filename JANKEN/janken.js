function janken(a)
{
    let result = a;
    result = gutipa(result);

    console.log(result);

    let hand = Math.random()*3;
    hand = gutipa(hand);

    console.log(hand);

    let Kekka = null;

    if(hand == result)
    {
        Kekka = "どっちつかず";
    }
    else if((hand == "チョキ" && result == "グー")||(hand == "グー" && result == "パー")||(hand == "パー" && result == "チョキ"))
    {
        Kekka = "勝者";
    }
    else
    {
       Kekka = "敗者";
    }

    console.log(Kekka);

    let me = document.getElementById("MetaEngine");
    me.innerHTML = result;

    let pc = document.getElementById("PasoCon");
    pc.innerHTML = hand;

    let keka = document.getElementById("Keka");
    keka.innerHTML = Kekka;
}

function janken01()
{
    result = prompt("what hand");
}

function gutipa(a)
{
    if(0<=a && a<1)
    {
        return "グー";
        //gu-
    }
    else if(1<=a && a<2)
    {
        return "チョキ";
        //choki
    }
    else if(2<=a && a<3)
    {
        return "パー";
        //pa-
    }
    else
    {
        return null;
    }
}