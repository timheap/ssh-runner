/*
 *   Copyright (C) 2009 Edward "Hades" Toroshchin <kde@hades.name>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef SSHRUNNER_H
#define SSHRUNNER_H

#include <Plasma/AbstractRunner>

class SSHConfigReader;

class SSHRunner : public Plasma::AbstractRunner {
	public:
		SSHRunner(QObject *parent, const QVariantList& args);
		~SSHRunner();
		KIcon mIcon;

		void match(Plasma::RunnerContext &context);
		void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match);
		QList<QAction*> actionsForMatch(const Plasma::QueryMatch &match);

	private:
		bool isRunning(const QString name);
		Plasma::QueryMatch constructMatch(QString host, Plasma::QueryMatch::Type priority);
		SSHConfigReader *rd;
};

K_EXPORT_PLASMA_RUNNER(krunner-ssh, SSHRunner)

#endif
