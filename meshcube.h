#ifndef MESHCUBE_H
#define MESHCUBE_H

#include <QPointF>
#include <QLineF>
#include <QVector>
#include <QDebug>

class MeshCube
{
private:
    struct Vec3
    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        Vec3() = default;

        Vec3(const float& x, const float& y, const float& z)
        {
            this->x = x; this->y = y; this->z = z;
        }
    };

public:
    //MeshCube() = default;

    //ебнуть размер куба
    //мне не нравится
    MeshCube(const float& size = 10.0f, const float& z = 50.0f)
    {
        vertices[0] = Vec3(- size / 2, size / 2, z);
        vertices[1] = Vec3(size / 2, size / 2, z);
        vertices[2] = Vec3(size / 2, - size / 2, z);
        vertices[3] = Vec3(- size / 2, - size / 2, z);

        vertices[4] = Vec3(- size / 2, size / 2, z + size);
        vertices[5] = Vec3(size / 2, size / 2, z + size);
        vertices[6] = Vec3(size / 2, - size / 2, z + size);
        vertices[7] = Vec3(- size / 2, - size / 2, z + size);

        edges[0] = QLineF(Point2D(vertices[0]), Point2D(vertices[1]));
        edges[1] = QLineF(Point2D(vertices[1]), Point2D(vertices[2]));
        edges[2] = QLineF(Point2D(vertices[2]), Point2D(vertices[3]));
        edges[3] = QLineF(Point2D(vertices[3]), Point2D(vertices[0]));

        edges[4] = QLineF(Point2D(vertices[4]), Point2D(vertices[5]));
        edges[5] = QLineF(Point2D(vertices[5]), Point2D(vertices[6]));
        edges[6] = QLineF(Point2D(vertices[6]), Point2D(vertices[7]));
        edges[7] = QLineF(Point2D(vertices[7]), Point2D(vertices[4]));

        edges[8] = QLineF(Point2D(vertices[0]), Point2D(vertices[4]));
        edges[9] = QLineF(Point2D(vertices[1]), Point2D(vertices[5]));
        edges[10] = QLineF(Point2D(vertices[2]), Point2D(vertices[6]));
        edges[11] = QLineF(Point2D(vertices[3]), Point2D(vertices[7]));
    }

    ~MeshCube() { }

    //у нас 8 вертексов
    //пока без треугольников, так как тупо каркас
    QVector<Vec3> vertices {8};
    QVector<QLineF> edges {12};
    QVector<int> indexes;

    float f = 1000.0f;

    Vec3 RotateX(Vec3 p, float a)
    {
        return Vec3(p.x, p.y*cos(a) - p.z*sin(a), p.y*sin(a) + p.z*cos(a));
    }
    Vec3 RotateY(Vec3 p, float a)
    {
        return Vec3(p.x*cos(a) + p.z*sin(a), p.y, -p.x*sin(a) + p.z*cos(a));
    }
    Vec3 RotateZ(Vec3 p, float a)
    {
        return Vec3(p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a), p.z);
    }

    QVector<Vec3> rotatedV {8};
    QVector<QLineF> rotatedE {12};


    //в меши
    void Rotate(const float& angleX = 0.0f, const float& angleY = 0.0f)
    {
        auto cz = 50 + 10/2;;

        for (int i = 0; i < 8; i++)
        {
            Vec3 v = vertices[i];
            v.z -= cz;
            v = RotateX(v, angleX * M_PI / 180.0f);
            v = RotateY(v, angleY * M_PI / 180.0f);
            v.z += cz;
            rotatedV[i] = v;
        }

        //мне не нравится
        rotatedE[0] = QLineF(Point2D(rotatedV[0]), Point2D(rotatedV[1]));
        rotatedE[1] = QLineF(Point2D(rotatedV[1]), Point2D(rotatedV[2]));
        rotatedE[2] = QLineF(Point2D(rotatedV[2]), Point2D(rotatedV[3]));
        rotatedE[3] = QLineF(Point2D(rotatedV[3]), Point2D(rotatedV[0]));

        rotatedE[4] = QLineF(Point2D(rotatedV[4]), Point2D(rotatedV[5]));
        rotatedE[5] = QLineF(Point2D(rotatedV[5]), Point2D(rotatedV[6]));
        rotatedE[6] = QLineF(Point2D(rotatedV[6]), Point2D(rotatedV[7]));
        rotatedE[7] = QLineF(Point2D(rotatedV[7]), Point2D(rotatedV[4]));

        rotatedE[8] = QLineF(Point2D(rotatedV[0]), Point2D(rotatedV[4]));
        rotatedE[9] = QLineF(Point2D(rotatedV[1]), Point2D(rotatedV[5]));
        rotatedE[10] = QLineF(Point2D(rotatedV[2]), Point2D(rotatedV[6]));
        rotatedE[11] = QLineF(Point2D(rotatedV[3]), Point2D(rotatedV[7]));
    }

    //в scene
    inline QPointF Point2D(const Vec3& p) const
    {
        auto x_new = p.x * f / p.z;
        auto y_new = p.y * f / p.z;

        QPointF p_new = QPointF(x_new, y_new);

        qDebug() << "p_new " << p_new;

        return p_new;
    }
};

#endif // MESHCUBE_H
