#include "Board.h"
#include "Utility.h"
Board::Board()
{
    this->Blue = new Dabba(BLUE);
    this->Green = new Dabba(GREEN);
    this->Red = new Dabba(RED);
    this->Yellow = new Dabba(YELLOW);
}
Dabba* Board::getregion(color clr)
{
    if (clr == BLUE)
    {
        return Blue;
    }
    else if (clr == RED)
    {
        return Red;
    }
    else if (clr == GREEN)
    {
        return Green;
    }
    else if (clr == YELLOW)
    {
        return Yellow;
    }
}
Dabba* Board::getregion_i(int i)
{
    if (i == 1)
    {
        return Blue;
    }
    else if (i == 2)
    {
        return Red;
    }
    else if (i == 3)
    {
        return Green;
    }
    else if (i == 4)
    {
        return Yellow;
    }
}
void Board::draw_piece(sf::RenderWindow& window, int ri, int ci, int p, float rf,float cf,bool ishome)
{

    sf::Texture b;
    sf::Texture r;
    sf::Texture g;
    sf::Texture y;

    if (!b.loadFromFile("resources/Blue.png"))
    {
        cout << "ERROR!";
    }
    if (!r.loadFromFile("resources/Red.png"))
    {
        cout << "ERROR!";
    }
    if (!g.loadFromFile("resources/Green.png"))
    {
        cout << "ERROR!";
    }
    if (!y.loadFromFile("resources/Yellow.png"))
    {
        cout << "ERROR!";
    }

    sf::Sprite bp(b);
    sf::Sprite rp(r);
    sf::Sprite gp(g);
    sf::Sprite yp(y);

    if (ishome == true)
    {
        bp.setOrigin(40.0, 40.0);
        rp.setOrigin(40.0, 40.0);
        gp.setOrigin(40.0, 40.0);
        yp.setOrigin(40.0, 40.0);
        bp.setScale(0.6, 0.6);
        rp.setScale(0.6, 0.6);
        gp.setScale(0.6, 0.6);
        yp.setScale(0.6, 0.6);
    }
    else
    {
        bp.setScale(0.5, 0.5), rp.setScale(0.5, 0.5), gp.setScale(0.5, 0.5), yp.setScale(0.5, 0.5);
    }
    
    if (p == 1)
    {
        bp.setPosition(float(ci) * cf, float(ri) * rf);
        window.draw(bp);
        return;
    }
    else if (p == 2)
    {
        rp.setPosition(float(ci) * cf, float(ri) * rf);
        window.draw(rp);
        return;
    }
    else if (p == 3)
    {
        gp.setPosition(float(ci) * cf, float(ri) * rf);
        window.draw(gp);
        return;
    }
    else if (p == 4)
    {
        yp.setPosition(float(ci) * cf, float(ri) * rf);
        window.draw(yp);
        return;
    }

}
void Board::draw_safe(sf::RenderWindow& window, int ri, int ci, float sp, color clr)
{
    int a = getregion(clr)->getsafesize();

    sf::Texture b;
    sf::Texture r;
    sf::Texture g;
    sf::Texture y;

    if (!b.loadFromFile("resources/Blue.png"))
    {
        cout << "ERROR!";
    }
    if (!r.loadFromFile("resources/Red.png"))
    {
        cout << "ERROR!";
    }
    if (!g.loadFromFile("resources/Green.png"))
    {
        cout << "ERROR!";
    }
    if (!y.loadFromFile("resources/Yellow.png"))
    {
        cout << "ERROR!";
    }

    sf::Sprite bp(b);
    sf::Sprite rp(r);
    sf::Sprite gp(g);
    sf::Sprite yp(y);

    bp.setScale(0.5, 0.5), rp.setScale(0.5, 0.5), gp.setScale(0.5, 0.5), yp.setScale(0.5, 0.5);


    for (int i = 1; i < getregion(clr)->getsafesize(); i++)
    {
        int p = getregion(clr)->getsafe(i);
        if (p == 1)
        {
            bp.setPosition(float(ci) * sp, float(ri) * sp);
            window.draw(bp);
            return;
        }
        else if (p == 2)
        {
            rp.setPosition(float(ci) * sp, float(ri) * sp);
            window.draw(rp);
            return;
        }
        else if (p == 3)
        {
            gp.setPosition(float(ci) * sp, float(ri) * sp);
            window.draw(gp);
            return;
        }
        else if (p == 4)
        {
            yp.setPosition(float(ci) * sp, float(ri) * sp);
            window.draw(yp);
            return;
        }
        
    }


}
void Board::display(sf::RenderWindow& window, color** c, int** ind, bool** x)
{
    sf::Texture b;
    sf::Texture bg;

    if (!b.loadFromFile("resources/Board.jpg"))
    {
        cout << "ERROR!";
    }
    if (!bg.loadFromFile("resources/Background.png"))
    {
        cout << "ERROR!";
    }


    sf::Sprite s(b);
    sf::Sprite bcg(bg);
    window.draw(bcg);
    window.draw(s);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (ind[i][j] == 14)
            {
                draw_safe(window, i, j, 40.5, c[i][j]);
            }
            else
            {
                if (c[i][j] == RED)
                {
                    if (x[i][j] == true)
                    {
                        draw_piece(window, i, j, Red->gethomegoti(ind[i][j]), 40.0,40.0,x[i][j]);
                    }
                    else
                    {

                        draw_piece(window, i, j, Red->getgoti(ind[i][j]), 40.0,40.0, x[i][j]);


                    }
                }
                else if (c[i][j] == BLUE)
                {
                    if (x[i][j] == true)
                    {
                        draw_piece(window, i, j, Blue->gethomegoti(ind[i][j]), 40.5, 40.5, x[i][j]);
                    }
                    else
                    {

                        draw_piece(window, i, j, Blue->getgoti(ind[i][j]), 40.5,40.5, x[i][j]);

                    }
                }
                else if (c[i][j] == GREEN)
                {
                    if (x[i][j] == true)
                    {
                        draw_piece(window, i, j, Green->gethomegoti(ind[i][j]), 40.5, 40.5, x[i][j]);
                    }
                    else
                    {

                        draw_piece(window, i, j, Green->getgoti(ind[i][j]), 40.0,40.5, x[i][j]);

                    }
                }
                else if (c[i][j] == YELLOW)
                {
                    if (x[i][j] == true)
                    {
                        draw_piece(window, i, j, Yellow->gethomegoti(ind[i][j]), 40.5, 40.5, x[i][j]);
                    }
                    else
                    {

                        draw_piece(window, i, j, Yellow->getgoti(ind[i][j]), 40.0,40.5, x[i][j]);

                    }
                }
            }


        }
    }
}
bool Board::ishfull(color clr)
{
    if (clr == BLUE)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Blue->gethomegoti(i) != 1)
            {
                return false;
            }
        }
        return true;
    }
    else if (clr == RED)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Red->gethomegoti(i) != 2)
            {
                return false;
            }
        }
        return true;
    }
    else if (clr == GREEN)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Green->gethomegoti(i) != 3)
            {
                return false;
            }
        }
        return true;
    }
    else if (clr == YELLOW)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Yellow->gethomegoti(i) != 4)
            {
                return false;
            }
        }
        return true;
    }
}
void Board::send_back(int val)
{
    for (int i = 0; i < 4; i++)
    {
        if (getregion(color(val))->gethomegoti(i) == 0)
        {
            getregion(color(val))->sethomegoti(val, i);
            break;
        }
    }
}

void Board::move(int si, int safei, color sclr, bool sh, int val, int t, bool& iskill)
{
    //HOME
    if (sh == true)
    {
        getregion(sclr)->setsafe(getregion(sclr)->gethomegoti(si));
        getregion(sclr)->sethomegoti(0, si);
        return;
    }
    //REGIONS
    Dabba* d = getregion(color(convert_clr(sclr) + 1));
    if (sclr == YELLOW)
    {
        d = Blue;
    }

    if (si <= 6 && getregion(sclr)->getgoti(si) != convert_clr(sclr) && si + val + 6 >= 13 && si + val + 6 <= 19)
    {
        if (si + val + 6 == 14)
        {
            getregion(sclr)->setsafe(getregion(sclr)->getgoti(si));
            getregion(sclr)->setgoti(0, si);
        }
        else
        {
            if (getregion(sclr)->getgoti(si + val + 6) != 0)
            {
                send_back(getregion(sclr)->getgoti(si + val + 6));
                iskill = true;

            }
            getregion(sclr)->setgoti(getregion(sclr)->getgoti(si), si + val + 6);
            getregion(sclr)->setgoti(0, si);
        }
    }
    else if (si + val >= 19)
    {
        if (si == 14)
        {
            int v = (si + val) - 19;
            if (d->getgoti(v) != 0)
            {
                send_back(d->getgoti(v));
                iskill = true;
            }
            d->setgoti(getregion(sclr)->getsafe(safei), v);
            getregion(sclr)->popsafe(safei);
        }
        else
        {
            int v = (si + val) - 19;
            if (d->getgoti(v) != 0)
            {
                send_back(d->getgoti(v));
                iskill = true;
            }
            d->setgoti(getregion(sclr)->getgoti(si), v);
            getregion(sclr)->setgoti(0, si);
        }
    }
    else
    {
        if (si == 14)
        {
            if (getregion(sclr)->getgoti(si + val) != 0)
            {
                send_back(getregion(sclr)->getgoti(si + val));
                iskill = true;

            }
            getregion(sclr)->setgoti(getregion(sclr)->getsafe(safei), si + val);
            getregion(sclr)->popsafe(safei);
        }
        else if (si + val == 12)
        {
            getregion(sclr)->setcount();
        }
        else
        {
            if (getregion(sclr)->getgoti(si + val) != 0)
            {
                send_back(getregion(sclr)->getgoti(si + val));
                iskill = true;
            }
            getregion(sclr)->setgoti(getregion(sclr)->getgoti(si), si + val);
            getregion(sclr)->setgoti(0, si);
        }

    }
}