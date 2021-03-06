#ifndef VIEWERRESOURCE_H
#define VIEWERRESOURCE_H

#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>
#include <QVector>

namespace vnotex
{
    // Resource for Web viewer.
    struct ViewerResource
    {
        struct Resource
        {
            void init(const QJsonObject &p_obj)
            {
                m_name = p_obj[QStringLiteral("name")].toString();
                m_enabled = p_obj[QStringLiteral("enabled")].toBool();

                m_styles.clear();
                auto stylesArray = p_obj[QStringLiteral("styles")].toArray();
                for (const auto &ele : stylesArray) {
                    m_styles << ele.toString();
                }

                m_scripts.clear();
                auto scriptsArray = p_obj[QStringLiteral("scripts")].toArray();
                for (const auto &ele : scriptsArray) {
                    m_scripts << ele.toString();
                }
            }

            QJsonObject toJson() const
            {
                QJsonObject obj;
                obj[QStringLiteral("name")] = m_name;
                obj[QStringLiteral("enabled")] = m_enabled;

                QJsonArray stylesArray;
                for (const auto &ele : m_styles) {
                    stylesArray.append(ele);
                }
                obj[QStringLiteral("styles")] = stylesArray;

                QJsonArray scriptsArray;
                for (const auto &ele : m_scripts) {
                    scriptsArray.append(ele);
                }
                obj[QStringLiteral("scripts")] = scriptsArray;
                return obj;
            }

            QString m_name;

            bool m_enabled = true;

            QStringList m_styles;

            QStringList m_scripts;
        };

        void init(const QJsonObject &p_obj)
        {
            m_template = p_obj[QStringLiteral("template")].toString();

            auto ary = p_obj[QStringLiteral("resources")].toArray();
            m_resources.resize(ary.size());
            for (int i = 0; i < ary.size(); ++i) {
                m_resources[i].init(ary[i].toObject());
            }
        }

        QJsonObject toJson() const
        {
            QJsonObject obj;
            obj[QStringLiteral("template")] = m_template;

            {
                QJsonArray ary;
                for (const auto &ele : m_resources) {
                    ary.append(ele.toJson());
                }
                obj[QStringLiteral("resources")] = ary;
            }

            return obj;
        }

        // HTML template file.
        QString m_template;

        // Resources to fill in the template.
        QVector<Resource> m_resources;
    };

}

#endif // VIEWERRESOURCE_H
