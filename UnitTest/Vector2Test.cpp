#include "gtest/gtest.h"
#include "WMath/Vector2.hpp"

using namespace WMath;

TEST(Vector2Test, CopyAndMove)
{
    Vector2 v1(1, 2);
    Vector2 v2(v1);
    Vector2 v3(std::move(v1));
    Vector2 v4 = v2;
    Vector2 v5 = std::move(v2);
    
    EXPECT_EQ(v1.x, 0);
    EXPECT_EQ(v1.y, 0);
    EXPECT_EQ(v2.x, 0);
    EXPECT_EQ(v2.y, 0);
    EXPECT_EQ(v3.x, 1);
    EXPECT_EQ(v3.y, 2);
    EXPECT_EQ(v4.x, 1);
    EXPECT_EQ(v4.y, 2);
    EXPECT_EQ(v5.x, 1);
    EXPECT_EQ(v5.y, 2);
}

TEST(Vector2Test, Arithmetics)
{
    EXPECT_TRUE(Equals(Vector2(1, 2) + Vector2(3, 4), Vector2(4, 6)));
    EXPECT_TRUE(Equals(Vector2(1, 2) - Vector2(3, 4), Vector2(-2, -2)));
    EXPECT_TRUE(Equals(Vector2(1, 2) * Vector2(3, 4), Vector2(3, 8)));
    EXPECT_TRUE(Equals(Vector2(1, 2) / Vector2(3, 4), Vector2(1.0f / 3.0f, 0.5f)));
    
    EXPECT_TRUE(Equals(Vector2(1, 2) * 2, Vector2(2, 4)));
    EXPECT_TRUE(Equals(2 * Vector2(1, 2), Vector2(2, 4)));
    EXPECT_TRUE(Equals(Vector2(1, 2) / 2, Vector2(0.5f, 1.0f)));
    EXPECT_TRUE(Equals(2 / Vector2(1, 2), Vector2(2, 1)));
}

TEST(Vector2Test, Equals)
{
    EXPECT_TRUE(Equals(Vector2(5, 2), Vector2(5, 2)));
    EXPECT_FALSE(Equals(Vector2(5, 2), Vector2(5, 3)));
    EXPECT_FALSE(Equals(Vector2(5, 2), Vector2(6, 2)));
    EXPECT_TRUE(Equals(Vector2(2, 2), Vector2(4, 4) / 2));
}

TEST(Vector2Test, Magnitude)
{
    EXPECT_TRUE(Equals(Vector2(3, 4).Magnitude(), 5));
    EXPECT_TRUE(Equals(Vector2(3, 4).SqrMagnitude(), 25));
}

TEST(Vector2Test, Normalize)
{
    Vector2 v(3, 4);
    v.Normalize();
    EXPECT_TRUE(Equals(v, Vector2(0.6f, 0.8f)));
    EXPECT_TRUE(Equals(Vector2(3, 4).Normalized(), Vector2(0.6f, 0.8f)));
}

TEST(Vector2Test, Angle)
{
    EXPECT_EQ(Vector2::Angle({1, 0}, {0, 1}), 90);
    EXPECT_EQ(Vector2::Angle({1, 0}, {1, 0}), 0);
    EXPECT_EQ(Vector2::Angle({1, 0}, {-1, 0}), 180);
    EXPECT_EQ(Vector2::Angle({1, 0}, {0, -1}), -90);
    EXPECT_EQ(Vector2::Angle({1, 0}, {1, 1}), 45);

    EXPECT_EQ(Vector2::AbsAngle({1, 0}, {0, 1}), 90);
    EXPECT_EQ(Vector2::AbsAngle({1, 0}, {0, -1}), 90);
}

TEST(Vector2Test, Cross)
{
    EXPECT_EQ(Vector2::Cross({1, 0}, {0, 1}), 1);
    EXPECT_EQ(Vector2::Cross({1, 0}, {1, 0}), 0);
    EXPECT_EQ(Vector2::Cross({1, 0}, {-1, 0}), 0);
    EXPECT_EQ(Vector2::Cross({1, 0}, {0, -1}), -1);
    EXPECT_EQ(Vector2::Cross({1, 0}, {1, 1}), 1);
}

TEST(Vector2Test, Dot)
{
    EXPECT_EQ(Vector2::Dot({1, 0}, {0, 1}), 0);
    EXPECT_EQ(Vector2::Dot({1, 0}, {1, 0}), 1);
    EXPECT_EQ(Vector2::Dot({1, 0}, {-1, 0}), -1);
    EXPECT_EQ(Vector2::Dot({1, 0}, {0, -1}), 0);
    EXPECT_EQ(Vector2::Dot({1, 0}, {1, 1}), 1);
}

TEST(Vector2Test, Distance)
{
    EXPECT_EQ(Vector2::Distance({0, 0}, {0, 1}), 1);
    EXPECT_EQ(Vector2::Distance({0, 0}, {1, 0}), 1);
    EXPECT_EQ(Vector2::Distance({0, 0}, {1, 1}), Sqrt(2));
    EXPECT_EQ(Vector2::Distance({0, 0}, {2, 2}), Sqrt(8));
}

TEST(Vector2Test, Lerp)
{
    EXPECT_TRUE(Equals(Vector2::Lerp({0, 0}, {1, 1}, 0.25f), Vector2(0.25f, 0.25f)));
    EXPECT_TRUE(Equals(Vector2::Lerp({0, 0}, {1, 1}, 0.5f), Vector2(0.5f, 0.5f)));
    EXPECT_TRUE(Equals(Vector2::Lerp({0, 0}, {1, 1}, 0.75f), Vector2(0.75f, 0.75f)));

    EXPECT_TRUE(Equals(Vector2::Lerp({1, 1}, {0, 0}, 0.25f), Vector2(0.75f, 0.75f)));
    EXPECT_TRUE(Equals(Vector2::Lerp({1, 1}, {0, 0}, 0.5f), Vector2(0.5f, 0.5f)));
    EXPECT_TRUE(Equals(Vector2::Lerp({1, 1}, {0, 0}, 0.75f), Vector2(0.25f, 0.25f)));
}

TEST(Vector2Test, Slerp)
{
    EXPECT_EQ(Vector2::Slerp({0, 0}, {1, 1}, 0.25f), Vector2(0.382683f, 0.382683f));
    EXPECT_EQ(Vector2::Slerp({0, 0}, {1, 1}, 0.5f), Vector2(0.707107f, 0.707107f));
    EXPECT_EQ(Vector2::Slerp({0, 0}, {1, 1}, 0.75f), Vector2(0.923880f, 0.923880f));

    EXPECT_EQ(Vector2::Slerp({1, 1}, {0, 0}, 0.25f), Vector2(0.382683f, 0.382683f));
    EXPECT_EQ(Vector2::Slerp({1, 1}, {0, 0}, 0.5f), Vector2(0.707107f, 0.707107f));
    EXPECT_EQ(Vector2::Slerp({1, 1}, {0, 0}, 0.75f), Vector2(0.923880f, 0.923880f));
}