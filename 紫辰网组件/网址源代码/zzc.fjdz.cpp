#pragma once
    #include<windows.h>
    #include<iostream>
    using namespace std;
    typedef struct Frame
    { 
        COORD position[2];          
        //  COORD ��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ
        // �䶨��Ϊ��
        // typedef struct _COORD { 
        //         SHORT X;
        //         SHORT Y;
        //       } COORD;
     
        int flag;
     
    }Frame;
     
     
     
     
    class Game
     
    { 
     
    public:
     
        COORD position[10];
     
        COORD bullet[10];
     
        Frame enemy[8];
     
        int score;
     
        int rank;
     
        int rankf;
     
        string title;
     
        int flag_rank;
     
     
        // ���캯��
        Game();        
     
     
     
        //��ʼ������
     
        void initPlane();
     
        void initBullet();
     
        void initEnemy();
     
     
     
        //��ʼ������һ��
     
        //void initThisBullet( COORD );
     
        //void initThisEnemy( Frame );
     
     
     
        void planeMove(char);
     
        void bulletMove();
     
        void enemyMove();
     
     
     
        //�������
     
        void drawPlane();
     
        void drawPlaneToNull();
     
        void drawBullet();
     
        void drawBulletToNull();
     
        void drawEnemy();
     
        void drawEnemyToNull();
     
     
     
        //�������һ��
     
        void drawThisBulletToNull(COORD);
     
        void drawThisEnemyToNull(Frame);
     
     
        void Pause();
     
        void Playing();
     
        void judgePlane();
     
        void judgeEnemy();
     
        void Shoot();
     
        void GameOver();
     
        void printScore();
     
    };
     
     
     
     
    void SetPos(COORD a);
    void SetPos(int i, int j);
    void HideCursor();
    void drawRow(int y, int x1, int x2, char ch);
    void drawRow(COORD a, COORD b, char ch);
    void drawCol(int x, int y1, int y2, char ch);
    void drawCol(COORD a, COORD b, char ch);
    void drawFrame(COORD a, COORD  b, char row, char col);
    void drawFrame(int x1, int y1, int x2, int y2, char row, char col);
    void drawFrame(Frame frame, char row, char col);
    void drawPlaying();
    int random(int a, int b);
    COORD random(COORD a, COORD b);
    bool  judgeCoordInFrame(Frame frame, COORD spot);
    void printCoord(COORD a);
    void printFrameCoord(Frame a);
    int drawMenu();
     
     


    #include<string>
    #include<conio.h>
     
    using namespace std;
     
     
    // ���幹�캯��
    // ���캯��������ĳ�Ա������ֻҪ���������͵��¶��󣬶�Ҫִ�й��캯����
    // ���캯���Ĺ����Ǳ�֤ÿ����������ݳ�Ա���к��ʵĳ�ʼֵ��
    // ���캯��ͨ��ʹ�ù��캯����ʼ���б�����ʼ�������ݳ�Ա��
    // ��Ȼ����˴�һ����ʡ�Գ�ʼ���б����ڹ��캯���ĺ������ڶ����ݳ�Ա��ֵ�ǺϷ��ġ�
    // ע�⣬���캯�������������������ͬ�����Ҳ���ָ���������͡��������κκ���һ����
    // ���ǿ���û���βΣ�Ҳ���Զ������βΡ�
    Game::Game()
     
    { 
        // �������Ա���������г�ʼ��
        initPlane();
     
        initBullet();
     
        initEnemy();
        
     
        // ��ʼ���ĸ�int�����ݳ�Ա�����ø�ֵ�ķ�ʽ���г�ʼ��
        // string���͵����ݳ�Աtitleû�н��г�ʼ������Ϊ��
        // string�������һ����׼�������ͣ������ඨ����������Ĭ�Ϲ��캯����
        // ��ЩĬ�Ϲ��캯���Ὣ�����ʼ��Ϊ�����Ĭ��״̬��
        //  string��Ĭ�Ϲ��캯����������ַ������൱��"" ��
        score = 0;
     
        rank = 25;
     
        rankf = 0;
     
        flag_rank = 0;
     
    }
     
     
    // ��Ա�����ȿ��Զ���������ڲ���Ҳ���Զ���������ⲿ��
    // �����ⲿ����ĳ�Ա��������ָ��������������������У�����
    //  Game::initPlane�Ķ���ʹ�� ����������� ��ָ������ Game����initPlane�����Ķ��塣
    // ���ǳ�ʼ��ս��λ�õĳ�Ա����
    void Game::initPlane()
     
    { 
     
        COORD centren;
        centren.X = 39;
        centren.Y = 22;
     
        position[0].X = position[5].X = position[7].X = position[9].X = centren.X;
     
        position[1].X = centren.X - 2;
     
        position[2].X = position[6].X = centren.X - 1;
     
        position[3].X = position[8].X = centren.X + 1;
     
        position[4].X = centren.X + 2;
     
        for (int i = 0; i <= 4; i++)
     
            position[i].Y = centren.Y;
     
        for (int i = 6; i <= 8; i++)
     
            position[i].Y = centren.Y + 1;
     
        position[5].Y = centren.Y - 1;
     
        position[9].Y = centren.Y - 2;
     
        // �����������Ĵ�����ʵ����Ϊ�˳�ʼ��ս����ʮ�����ֵ�λ�ã�ս�������������ʾ��   
        //                   |
        //                     |
        //                   00000
        //                    000
        //   ��һ��5��0���������ζ�Ӧ��position[1]position[2]position[0]position[3]position[4]
        //   �ڶ�������0���������ζ�Ӧ��position[6]position[7]position[8]
        //   ����0�������|����������������ζ�Ӧ��position[5]position[9]
    }
     
     
     
    // ���ǳ�ʼ��ս�����εĳ�Ա����
    // ս������״���������ʾ��
    //                   |
    //                     |
    //                   00000
    //                    000
    // �ڸú����е�����SetPos()���������ù���
    void Game::drawPlane()
    { 
        for (int i = 0; i<9; i++)
        { 
            SetPos(position[i]);   
            // �˴�����SetPos()������������õ���position[i]ָ����λ��
     
            if (i != 5)
     
                cout << "O";
     
            else if (i == 5)
     
                cout << "|";
        }
    }
     
     
    // �����Ա����ͨ����ս����ÿ�����괦���" "������"0"��"|"��
    // ���ﵽ��ս��������Ŀ�ġ�
    void Game::drawPlaneToNull()
    { 
        for (int i = 0; i<9; i++)
        { 
            SetPos(position[i]);
     
            cout << " ";
        }
    }
     
     
     
    // �ó�Ա����������ʼ���ӵ���
    // ����ÿ���ӵ���Y�����ʼ��Ϊ30��bullet[i].Y = 30������ʾ�ӵ�����ʧЧ״̬
    void Game::initBullet()
    { 
        for (int i = 0; i<10; i++)
     
            bullet[i].Y =30;
    }
     
     
     
     
    // �ó�Ա�������������ӵ�
    // ���ȼ��ÿ���ӵ�����Ч�ԣ�����ӵ���Ч����λ�����ӵ������괦����� "^"����ʾ���ӵ���
    // ����ӵ�����Ч�ģ��򲻻���
    void Game::drawBullet()
     
    { 
     
        for (int i = 0; i<10; i++)
     
        { 
            
            if (bullet[i].Y != 30)
     
            { 
     
                SetPos(bullet[i]);
     
                cout << "^";
            }
     
        }
     
    }
     
     
     
     
    void Game::drawBulletToNull()
     
    { 
     
        for (int i = 0; i<10; i++)
     
            if (bullet[i].Y != 30)
     
            { 
     
                COORD pos = { bullet[i].X, bullet[i].Y + 1 };
     
                SetPos(pos);
     
                cout << " ";
     
            }
     
    }
     
     
     
    // �������������ʼ�л���λ�ã�
    // ��Ļ����ֻ��ͬʱ���ڰ˼ܵл���
    // ��ÿ�ܵл������½ṹ��Frame����ʾ��������ʾ��
    //     typedef struct Frame
    //        { 
    //          COORD position[2];
    //          int flag;
    //        }Frame;
    void Game::initEnemy()
     
    { 
     
        COORD a = { 1, 1 };
        COORD b = { 45, 15 };
        //
     
        for (int i = 0; i<8; i++)
     
        { 
     
            enemy[i].position[0] = random(a, b);  
            //  random(a, b)�ǵ�����һ�����صĺ���������ʾ������a��b֮��ľ��ο�
            //  ���������һ������ֵ������������ֵ��Ϊ�л������Ͻǵ����ꡣ
            // enemy[i].position[0]����һ��Frame�ṹ�����͵ı�����
            // ����˵л�i�����Ͻǵ����ꡣ
     
            enemy[i].position[1].X = enemy[i].position[0].X + 3;
            enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
            // enemy[i].position[1]Ҳ����һ��Frame�ṹ�����͵ı�����
            // ����˵л�i�����½ǵ����ꡣ
     
     
        }
     
    }
     
     
    // ������Ҫ���ݵл������Ͻ���������½����껭���л���
    // ��Ȼ���л�������������ʾ��
    //   --
    //  |  |
    //   --
    void Game::drawEnemy()
     
    { 
     
        for (int i = 0; i<8; i++)
     
            drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');
     
    }
     
     
    // ���л�������ͨ������հ׵ķ�ʽ
    void Game::drawEnemyToNull()
     
    { 
     
        for (int i = 0; i<8; i++)
     
        { 
     
            drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');
     
        }
     
    }
     
     
    // �ó�Ա��������ʹ����Ϸ��ͣ
    void Game::Pause()
     
    { 
     
        SetPos(61, 2);
     
        cout << "         ";
     
        SetPos(61, 2);
     
        cout << "��ͣ��...";
     
        // ������"��ͣ��..."����ʾ�Ժ󣬳���ͣ�Ľ��հ��µİ�����
        // ������'p'���Ժ�˵��Ҫ�˳���ͣ״̬����ʱ��Ҫ���"��ͣ��..."����ʾ
        // ͨ������հ� "         "�����串�ǣ��ﵽЧ��
        char c = _getch();
     
        while (c != 'p')
     
            c = _getch();
     
        SetPos(61, 2);
     
        cout << "         ";
     
    }
     
     
    // �ó�Ա�����ù���Ӧս����һ������
    // a,s,w,d,������ս�����ƶ�
    void Game::planeMove(char x)
     
    { 
     
        if (x == 'a')
     
            if (position[1].X != 1)
     
                for (int i = 0; i <= 9; i++)
     
                    position[i].X -= 2;
        // �����Ұ��� 'a' ����˵���������ս�������ƶ�һ�����루2����λ����
        // ���ȼ�⣬ս����������λ�����꣨��position[1].X����û�дﵽ��߽磬
        // ��������˱߽磬�ǾͲ������ƶ������û�дﵽ�߽磬��ս��10�����ֵ�Xֵ��С2��
     
     
        if (x == 's')
     
            if (position[7].Y != 23)
     
                for (int i = 0; i <= 9; i++)
     
                    position[i].Y += 1;
        // �����Ұ��� 's' ����˵���������ս�������ƶ�һ�����루1����λ����
        // ���ȼ�⣬ս������ײ���λ�����꣨��position[6].Y����position[7].Y����position[8].Y����û�дﵽ�±߽磬
        //  ��������˱߽磬�ǾͲ������ƶ������û�дﵽ�߽磬��ս��10�����ֵ�Yֵ����1��
     
     
        if (x == 'd')
     
            if (position[4].X != 47)
     
                for (int i = 0; i <= 9; i++)
     
                    position[i].X += 2;
        // �����Ұ��� 'd' ����˵���������ս�������ƶ�һ�����루2����λ����
        // ���ȼ�⣬ս�������Ҳ��λ�����꣨��position[4].X����û�дﵽ�ұ߽磬
        //  ��������˱߽磬�ǾͲ������ƶ������û�дﵽ�߽磬��ս��10�����ֵ�Xֵ����2��
     
     
     
        if (x == 'w')
     
            if (position[5].Y != 3)
     
                for (int i = 0; i <= 9; i++)
     
                    position[i].Y -= 1;
        // �����Ұ���'w'����˵���������ս�������ƶ�һ�����루1����λ����
        // ���ȼ�⣬ս���������λ�����꣨��position[5].Y����û�дﵽ�ϱ߽磬
        //  ��������˱߽磬�ǾͲ������ƶ������û�дﵽ�߽磬��ս��10�����ֵ�Yֵ����1��
     
    }
     
     
    // �˳�Ա����������Ӧһ���ӵ����˶�
    // ÿ���ӵ��˶�����Ļ�ӵ������궼����ֱ仯����
    // ���ж��ӵ��Ƿ���Ч�����ж����if (bullet[i].Y != 30)����
    // ���ӵ���Ч�������ӵ���Y�������1��X���겻�䣬
    // ����ӵ��������֮���Ƿ�ﵽ�ϱ߽磬����ﵽ�ϱ߽磬�򽫸��ӵ�����Ļ�ϲ�����
    // ͬʱ�������ӵ���ΪʧЧ״̬���� bullet[i].Y = 30��
    void Game::bulletMove()
     
    { 
     
        for (int i = 0; i<10; i++)
     
        { 
     
            if (bullet[i].Y != 30)
     
            { 
     
                bullet[i].Y -= 1;
     
                if (bullet[i].Y == 1)
     
                { 
     
                    COORD pos = { bullet[i].X, bullet[i].Y + 1 };
     
                    drawThisBulletToNull(pos);
     
                    bullet[i].Y = 30;
     
                }
     
     
     
            }
     
        }
     
    }
     
     
    // �ó�Ա����������Ӧһ�εл����ƶ�
    // �����ϱ���ͬʱ���ְ˼ܵл�����ˣ�
    // �����ĳ�ܵл��˶����±߽紦�������øõл�������
    void Game::enemyMove()
     
    { 
     
        for (int i = 0; i<8; i++)
     
        { 
     
            for (int j = 0; j<2; j++)
     
                enemy[i].position[j].Y++;
            // ���ǽ�ÿ�ܵл������ϽǺ����½������Yֵ����1��
            // ��ʾ�õл���������һ������
     
            // ���������һ�������ĵл������½������Yֵ�Ƿ�ﵽ24��
            // ����ﵽ������л��Ѿ��˶����±߽��ˣ�
            // ��ʱ��Ҫ������øõл�������
            if (24 == enemy[i].position[1].Y)
     
            { 
     
                COORD a = { 1, 1 };
     
                COORD b = { 45, 3 };
     
                enemy[i].position[0] = random(a, b);
     
                enemy[i].position[1].X = enemy[i].position[0].X + 3;
     
                enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
     
            }
     
        }
     
    }
     
     
    // �ó�Ա���������ж�ս���Ƿ�׹�٣�
    // �����ж�ÿ�ܵл���ս����ÿ�������Ƿ��нӴ���
    // ����нӴ������ʾս��׹��
    void Game::judgePlane()
     
    { 
     
        for (int i = 0; i < 8; i++)
     
            for (int j = 0; j<9; j++)
     
                // �˴���ʵ��position[j]��ָս����10�����ֵ�COORD���꣬
                // ���еĳ�Ա�������Է������ݳ�Ա������
                // �˴�Ҳ����д��this-> position[j]����Ϊ
                // ��Ա��������һ�����ӵ������βΣ���ָ���������һ��ָ�룬
                // ��������β�����Ϊthis������ó�Ա�����Ķ������һ��
                // ��Ա�������ܶ���this�βΣ������ɱ����������ض��塣
                // ��Ա�����ĺ����������ʽʹ��thisָ�룬�����Ǳ�����ô����
                if (judgeCoordInFrame(enemy[i], position[j]))
     
                { 
     
                    SetPos(62, 1);
     
                    cout << "׹��";
     
                    drawFrame(enemy[i], '+', '+');
                    // ����ս����ײ�ĵл�����״����Ϊ:
                    //    ++
                    //   +  +
                    //    ++
                    
     
                    Sleep(1000);
     
                    GameOver();
     
                    break;
     
                }
     
    }
     
     
     
    void Game::drawThisBulletToNull(COORD c)
     
    { 
     
        SetPos(c);
     
        cout << " ";
     
    }
     
     
     
    void Game::drawThisEnemyToNull(Frame f)
     
    { 
     
        drawFrame(f, ' ', ' ');
     
    }
     
     
    // �ó�Ա�������α���ÿһ�ܵл���
    // ��ÿһ�ܵл�������ÿһ���ӵ����м�⣬
    // �жϵл��Ƿ����ӵ��нӴ�������нӴ������ʾ���ел���
    // ��ʱ���л����ӵ�������Ȼ���ڽ��涥����λ�ô��������һ�ܵл�
    void Game::judgeEnemy()
     
    { 
     
        for (int i = 0; i < 8; i++)
     
            for (int j = 0; j < 10; j++)
     
                if (judgeCoordInFrame(enemy[i], bullet[j]))
     
                { 
     
                    score += 5;
     
                    drawThisEnemyToNull(enemy[i]);
     
                    COORD a = { 1, 1 };
     
                    COORD b = { 45, 3 };
     
                    enemy[i].position[0] = random(a, b);
     
                    enemy[i].position[1].X = enemy[i].position[0].X + 3;
     
                    enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
     
                    drawThisBulletToNull(bullet[j]);
     
                    bullet[j].Y = 30;
     
                }
     
    }
     
     
    // �����Ա����������Ӧһ�����������
    // Ҳ���ǣ�����Ϸ�е�ʱ����Ұ���"k"������ִ�иú�����
    // �����ӵ�����COORD bullet[10]����ģ����ͬһʱ�̣�������ֻ����10���ӵ�ͬʱ���֡�
    // ��������ڲ���10���ӵ�������"k"����ս��Ӧ�÷����һ���ӵ���
    // ���ǣ����α���10���ӵ�����������һ��ʧЧ���ӵ���
    // ���������ӵ������µ����꣨ս�����ڿڣ�Ҳ���ǣ�position[5].X��position[5].Y - 1������
    // ���伤�Ȼ���˳�forѭ��������ִ����ϡ�
    void Game::Shoot()
     
    { 
     
        for (int i = 0; i<10; i++)
     
            if (bullet[i].Y == 30)
     
            { 
     
                bullet[i].X = position[5].X;
     
                bullet[i].Y = position[5].Y - 1;
     
                break;
     
            }
     
    }
     
     
     
    void Game::printScore()
     
    { 
     
        if (score == 120 && flag_rank == 0)
     
        { 
     
            rank -= 3;
     
            flag_rank = 1;
     
        }
     
     
     
        else if (score == 360 && flag_rank == 1)
     
        { 
     
            rank -= 5;
     
            flag_rank = 2;
     
        }
     
        else if (score == 480 && flag_rank == 2)
     
        { 
     
            rank -= 5;
     
            flag_rank = 3;
     
        }
     
        int x = rank / 5;
     
        SetPos(60, 6);
     
        cout << score;
     
     
     
        if (rank != rankf)
     
        { 
     
            SetPos(60, 7);
     
            if (x == 5)
     
                title = "��������Ա";
     
            else if (x == 4)
     
                title = "�м�����Ա";
     
            else if (x == 3)
     
                title = "�߼�����Ա";
     
            else if (x == 2)
     
                title = "���Ʒ���Ա";
     
            cout << title;
     
        }
     
        rankf = rank;
     
    }
     
     
    // �����Ա��������Ϸ����ѭ��������
    // ������������Ϸ���̡�
    void Game::Playing()
     
    { 
     
        //HANDLE MFUN;
     
        //MFUN= CreateThread(NULL, 0, MusicFun, NULL, 0, NULL);
     
     
     
        drawEnemy();
     
        drawPlane();
     
     
        int flag_bullet = 0;
     
        int flag_enemy = 0;
     
     
     
        while (1)
     
        { 
     
            Sleep(20);
     
            // ��������kbhit()��VC++6.0��Ϊ_kbhit()��
            // ���ܼ�����ֵ�� ��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
            // �÷���int kbhit(void);
            // ����ͷ�ļ��� include <conio.h>
            // kbhit()��ִ��ʱ,����Ƿ��а�������,�а��·��ط�0ֵ��û�а����򷵻�0���Ƿ�����������
            // ��ͬ��getch()����ִ��ʱ, ��ⰴ��ʲô��, ����������ú��������أ�Ҳ�Ͳ�������һ��������������������
            if (_kbhit())
     
            { 
     
                char x = _getch();
                // getch()�Ǳ�������õĺ��������������һ�������Ժ�����
                // ���û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س�
                // getch()���Ǳ�׼C�еĺ�����������C�����С�
                // ����ͷ�ļ���conio.h��������stdio.h��
                // ��ch = getch(); ��ȴ��㰴�������֮�󣬰Ѹü��ַ�����Ӧ��ASCII�븳��ch, ��ִ���������䡣
     
                if ('a' == x || 's' == x || 'd' == x || 'w' == x)
     
                { 
     
                    drawPlaneToNull();     // ��ս���Ȳ���
     
                    planeMove(x);          // ����������Ĳ���������ս����������и���
     
                    drawPlane();           // �������е����ݳ�Ա����ս�������꣬���µ����괦���»���ս��
     
                    judgePlane();          // �ж�ս���Ƿ���׹��
     
                }
     
                //  ��ĳһѭ�����У������⵽��'p'�����£�
                // �������Ҳ���Ϸ�������"��ͣ��..."��Ȼ������while()ѭ��һֱ�ȴ�'p'���ٴΰ��£�
                // ���'p'��û�а��£���һֱ����while()ѭ���ڣ���˲���ִ�к���ĳ�������ͣ��Ч����
                else if ('p' == x)
     
                    Pause();    
     
                // ����Ǽ�⵽'k'�����£�������Shoot()������
                else if ('k' == x)
     
                    Shoot();
     
                // ����Ǽ�⵽'k'�����£�������GameOver()������
                // GameOver()����ִ����Ϻ�ִ��break;�������whileѭ����ע�ⲻ��if (_kbhit())����
                // break������ڽ��������while��do while��for��switch��䣬���������ִ��Ȩ���ݸ�������
                // ����ֹ���֮�����䡣
                else if ('e' == x)
     
                { 
     
                    //CloseHandle(MFUN);
     
                    GameOver();
     
                    break;
     
                }
     
            }
     
     
            // �����������ӵ�
            if (0 == flag_bullet)
     
            { 
     
                bulletMove();           // ���½�������Ч�ӵ�������
     
                drawBulletToNull();     // �����ھ�������ӵ�����
     
                drawBullet();           // ���Ƴ��������ϵ��ӵ�
     
                judgeEnemy();          // �жϵл��Ƿ��ӵ�����
     
            }
     
            flag_bullet++;
     
            if (5 == flag_bullet)
     
                flag_bullet = 0;
     
     
     
            //  ����������л�
            if (0 == flag_enemy)
     
            { 
     
                drawEnemyToNull();     // �����еĵл�������
     
                enemyMove();           //  ���µл�������
     
                drawEnemy();           // ���Ƴ������������ϵĵл�
     
                judgePlane();          // �жϵл��Ƿ���ս���Ӵ�
     
            }
     
            flag_enemy++;
     
            if (flag_enemy >= rank)
     
                flag_enemy = 0;
     
     
     
            /* ����÷� */
     
            printScore();
     
        }
        
    }
     
     
     
    void Game::GameOver()
     
    { 
     
        system("cls");
     
        COORD p1 = { 28,9 };
     
        COORD p2 = { 53,15 };
     
        drawFrame(p1, p2, '=', '|');
     
        SetPos(36, 12);
     
        string str = "Game Over!";
     
        for (int i = 0; i<str.size(); i++)
     
        { 
     
            Sleep(80);
     
            cout << str[i];
     
        }
     
        Sleep(1000);
     
        system("cls");
     
        drawFrame(p1, p2, '=', '|');
     
        SetPos(31, 11);
     
        cout << "����л���" << score / 5 << " ��";
     
        SetPos(31, 12);
     
        cout << "�� �֣�" << score;
     
        SetPos(31, 13);
     
        cout << "��óƺţ�" << title;
     
        SetPos(30, 18);
     
        Sleep(1000);
     
        cout << "������ �ǣ�y��| ��n��";
     
    as:
     
        char x = _getch();
     
        if (x == 'n')
     
            exit(0);
     
        else if (x == 'y')
     
        { 
     
            system("cls");
     
            Game game;
     
            int a = drawMenu();       // ������Ϸ��ʼ�������˵�
     
            if (a == 2)
     
                game.rank = 20;
     
            system("cls");
     
            drawPlaying();           // ������Ϸ������
     
            game.Playing();
     
        }
     
        else goto as;
     
    }
     
     
     
     
     
     
     
     
     
    //
     
    void SetPos(COORD a)    // set cursor
     
    { 
     
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
     
        SetConsoleCursorPosition(out, a);
     
    }
     
     
     
    void SetPos(int i, int j)// set cursor
     
    { 
     
        COORD pos = { i, j };
     
        SetPos(pos);
     
    }
     
     
     
    void HideCursor()
     
    { 
     
        CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
     
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
     
    }
     
     
     
    //�ѵ�y�У�[x1, x2) ֮����������Ϊ ch
     
    void drawRow(int y, int x1, int x2, char ch)
     
    { 
     
        SetPos(x1, y);
     
        for (int i = 0; i <= (x2 - x1); i++)
     
            cout << ch;
        
     
    }
     
     
     
    //��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
     
    void drawRow(COORD a, COORD b, char ch)
     
    { 
     
        if (a.Y == b.Y)
     
            drawRow(a.Y, a.X, b.X, ch);
     
        else
     
        { 
     
            SetPos(0, 25);
     
            cout << "error code 01���޷�����У���Ϊ���������������(x)�����";
     
            system("pause");
     
        }
     
    }
     
     
     
    //�ѵ�x�У�[y1, y2] ֮����������Ϊ ch
     
    void drawCol(int x, int y1, int y2, char ch)
     
    { 
     
        int y = y1;
     
        while (y != y2 + 1)
     
        { 
     
            SetPos(x, y);
     
            cout << ch;
     
            y++;
     
        }
     
    }
     
     
     
    //��a, b ��������ͬ��ǰ���£������� [a, b] ֮�����Ϊ ch
     
    void drawCol(COORD a, COORD b, char ch)
     
    { 
     
        if (a.X == b.X)
     
            drawCol(a.X, a.Y, b.Y, ch);
     
        else
     
        { 
     
            SetPos(0, 25);
     
            cout << "error code 02���޷�����У���Ϊ��������ĺ�����(y)�����";
     
            system("pause");
     
        }
     
    }
     
     
     
    //���Ͻ����ꡢ���½����ꡢ��row����С���col�����
     
    void drawFrame(COORD a, COORD  b, char row, char col)
     
    { 
     
        drawRow(a.Y, a.X + 1, b.X - 1, row);
     
        drawRow(b.Y, a.X + 1, b.X - 1, row);
     
        drawCol(a.X, a.Y + 1, b.Y - 1, col);
     
        drawCol(b.X, a.Y + 1, b.Y - 1, col);
     
    }
     
     
     
    void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
     
    { 
     
        COORD a = { x1, y1 };
     
        COORD b = { x2, y2 };
     
        drawFrame(a, b, row, col);
     
    }
     
     
     
    void drawFrame(Frame frame, char row, char col)
     
    { 
     
        COORD a = frame.position[0];
     
        COORD b = frame.position[1];
     
        drawFrame(a, b, row, col);
     
    }
     
     
     
     
     
    // ������Ϸ����
    void drawPlaying()
     
    { 
     
        drawFrame(0, 0, 48, 24, '=', '|');//    draw map frame;
     
        drawFrame(49, 0, 79, 4, '-', '|');//        draw output frame
     
        drawFrame(49, 4, 79, 9, '-', '|');//        draw score frame
     
        drawFrame(49, 9, 79, 20, '-', '|');//    draw operate frame
     
        drawFrame(49, 20, 79, 24, '-', '|');//    draw other message frame
     
        SetPos(52, 6);
     
        cout << "�÷֣�";
     
        SetPos(52, 7);
     
        cout << "�ƺţ�";
     
        SetPos(52, 11);
     
        cout << "������ʽ��";
     
        SetPos(52, 13);
     
        cout << "  a,s,d,w������ս���ƶ�\n����k���������";
     
        SetPos(52, 15);
     
        cout << "  p����ͣ��Ϸ��";
     
        SetPos(52, 17);
     
        cout << "  e���˳���Ϸ��";
     
        SetPos(52,22);
     
        cout << " ��Ϸ����棬��Ҫ̰��Ŷ ";
     
     
    }
     
     
     
    // ��[a, b)֮�����һ�����������ע�ⲻ����b,
    // C����/C++��û���Դ���random(int number)������
    // ��1�������ֻҪ���������������Ҫ�趨��Χ�Ļ�����ֻҪ��rand()�Ϳ����ˣ�
    // rand()�᷵��һ�����ֵ,��Χ��0��RAND_MAX�䡣RAND_MAX������stdlib.h, ��ֵΪ2147483647��
    // ��2�������Ҫ�������һ����һ����Χ���������磬���Ҫ����1-100������������int num = rand() % 100 + 1;  
    //  һ���ԣ�rand() % (b - a + 1) + a �ͱ�ʾ [a,b]֮���һ�����������
    //  һ���ԣ�rand() % (b - a ) + a �ͱ�ʾ [a,b) ֮���һ�����������
    int random(int a, int b)
     
    { 
     
        int c = (rand() % (a - b)) + a;
     
        return c;
     
    }
     
     
     
    //��������������ľ��ο����������һ������
    COORD random(COORD a, COORD b)
     
    { 
     
        int x = random(a.X, b.X);
     
        int y = random(a.Y, b.Y);
     
        COORD c = { x, y };
     
        return c;
     
    }
     
     
     
     
     
    // �ú��������ж�ս����ĳһ�����Ƿ���л��нӴ�
    // �����л��нӴ����ж�Ϊ׹��
    bool  judgeCoordInFrame(Frame frame, COORD spot)
     
    { 
     
        if (spot.X >= frame.position[0].X)
     
            if (spot.X <= frame.position[1].X)
     
                if (spot.Y >= frame.position[0].Y)
     
                    if (spot.Y <= frame.position[1].Y)
     
                        return true;
     
        return false;
     
    }
     
     
     
    void printCoord(COORD a)
     
    { 
     
        cout << "( " << a.X << " , " << a.Y << " )";
     
    }
     
     
     
    void printFrameCoord(Frame a)
     
    { 
     
        printCoord(a.position[0]);
     
        cout << " - ";
     
        printCoord(a.position[1]);
     
    }
     
     
     
    // ������Ϸ���˵�����
    int drawMenu()
     
    { 
     
        SetPos(30, 1);
     
        cout << "�� �� �� ս";
     
        drawRow(3, 0, 79, '-');
     
        drawRow(5, 0, 79, '-');
     
        SetPos(28, 4);
     
        cout << "w �� s ѡ�� k ȷ��";
     
        SetPos(15, 11);
     
        cout << "1. �򵥵ĵ���";
     
        SetPos(15, 13);
     
        cout << "2. ���ĵ���";
     
        drawRow(20, 0, 79, '-');
     
        drawRow(22, 0, 79, '-');
     
        SetPos(47, 11);
     
        cout << "�򵥵ĵ��ˣ�";
     
        SetPos(51, 13);
     
        cout << "�򵥵������Ž������ƶ��ٶȡ�";
     
        SetPos(30, 21);
     
        cout << "copy right@";
     
        int j = 11;
     
        SetPos(12, j);
     
        cout << ">>";
     
     
     
        //drawFrame(45, 9, 79, 17, '=', '|');
     
     
     
        while (1)
     
        { 
            if (_kbhit())
     
            { 
     
                char x = _getch();
     
                switch (x)
     
                { 
     
                case 'w':
     
                { 
     
                    if (j == 13)
     
                    { 
     
                        SetPos(12, j);
     
                        cout << "  ";
     
                        j = 11;
     
                        SetPos(12, j);
     
                        cout << ">>";
     
                        SetPos(51, 13);
     
                        cout << " ";
     
                        SetPos(47, 11);
     
                        cout << "�򵥵ĵ��ˣ�";
     
                        SetPos(51, 13);
     
                        cout << "�򵥵������Ž������ƶ��ٶȣ��Ƚ����׶Ը�";
     
                    }
     
                    break;
     
                }
     
                case 's':
     
                { 
     
                    if (j == 11)
     
                    { 
     
                        SetPos(12, j);
     
                        cout << " ";
     
                        j = 13;
     
                        SetPos(12, j);
     
                        cout << ">>";
     
                        SetPos(51, 13);
     
                        cout << " ";
     
                        SetPos(47, 11);
     
                        cout << "���ĵ��ˣ�";
     
                        SetPos(51, 13);
     
                        cout << "���ĵ����ƶ��ٶȽϿ죬�ѶԸ�Ӵ��";
     
                    }
     
                    break;
     
                }
     
                case 'k':
     
                { 
     
                    if (j == 8)    
                        return 1;
     
                    else
                        return 2;
     
                }
     
                }
     
            }
     
        }
     
    }

     
    #include<time.h>
     
    #include<string>
     
     
    using namespace std;
     
     
    /*================== the main function ==================*/
     
    int main()
     
    { 
     
        //��Ϸ׼��
     
        srand((int)time(0));    
        // �����������
        // ������������������α�������������СM����ʽ�������ɵģ����в���ÿ��С���ж���һ����ʼֵ����������ӡ�
        // rand()����������������������������ⲻ�����������ϵ����������һ��α�������
        // �Ǹ���һ���������ǿ��Գ���Ϊ���ӣ�Ϊ��׼��ĳ�����ƹ�ʽ���������һϵ������
        // ����ϵ�����ܴ��ʱ�򣬾ͷ�����̬�������Ӷ��൱�ڲ���������������ⲻ���������������
        // �����������������������ӵ�ֵ�Ƕ��˵ģ��������ƻ���ϵͳ��
        //  void srand(unsigned int seed)
        // srand()��������rand()���������ʱ����������ӡ�����seed�����Ǹ�������
        // ���ÿ��seed������ֵͬ��rand()�������������ֵÿ�ξͻ�һ����
        // rand()�������������ÿ�����е�ʱ��������һ����ͬ�ġ���Ҫ��ͬ,�ú���srand()��ʼ������
        // ��������srand((unsigned int)(time(NULL))�ķ�����������ͬ����������ӣ���Ϊÿһ�����г����ʱ���ǲ�ͬ�ġ�
        // NULL��ֵΪ0���涨0���Ը�ֵ������ָ�룬��0������κ���ֵ�����ܸ�ֵ��ָ�롣
     
        HideCursor();    //���ع��
     
     
     
        Game game;
     
        int a = drawMenu();
     
        if (a == 2)
     
            game.rank = 20;
     
        system("cls");
     
        drawPlaying();
     
        game.Playing();
     
    }
